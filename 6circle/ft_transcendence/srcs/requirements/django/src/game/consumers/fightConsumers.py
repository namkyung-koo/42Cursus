import json, logging, asyncio

from channels.generic.websocket import AsyncWebsocketConsumer
from channels.layers import get_channel_layer
from users.models import User, UserRecordFightingGame
from game.info_fight import Room
from game.models import GameRoom
from game.utils import rating_calculator
from datetime import datetime
from users.utils import random_key, access_token_get_name
from channels.db import database_sync_to_async
from asgiref.sync import sync_to_async
from urllib.parse import parse_qs

logger = logging.getLogger(__name__)

class fightingConsumers(AsyncWebsocketConsumer):
    class RoomList:
        pass

    async def connect(self):
        self.game_group_name = ""
        self.rating_difference = 100
        self.create_time = datetime.now()
        query_string = parse_qs(self.scope['query_string'].decode())
        access_token = query_string.get('access', None)[0]
        self.user_name = access_token_get_name(access_token)

        if access_token == None or self.user_name == None:
            await self.close()
        
        self.display_name = await self.get_display_name()
        self.rating = await self.get_rating(self.user_name)
        await self.channel_layer.group_add("game_queue", self.channel_name)
        await self.accept()
        await self.send(text_data=json.dumps({
            "type" : "game.message",
            "data" : {
                "mode" : "connect",
                "name" : self.user_name,
                "display_name" : self.display_name,
            }
        }))
        try:
            await asyncio.wait_for(self.join_matching(), 10)
        except asyncio.exceptions.TimeoutError:
            await self.close()

    async def disconnect(self, close_code):
        try:
            cnt = await self.db_cnt()
            if cnt == 1:
                await self.db_delete()
                delattr(self.RoomList, self.game_group_name)
        except:
            logger.debug('No room')
        if close_code == 1000:
            if self.game_group_name:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        'type' : 'game.message',
                        'data' : {
                            'mode' : 'normal.termination',
                        }
                    }
                )
                await self.channel_layer.group_discard(self.game_group_name, self.channel_name)
        else:
            logger.error("websocket " + self.channel_name + ": abnormal.termination")
            if self.game_group_name:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        'type' : 'game.message',
                        'data' : {
                            'mode' : 'abnormal.termination',
                        }
                    }
                )
                await self.channel_layer.group_discard(self.game_group_name, self.channel_name)
        await self.close()

    async def receive(self, text_data):
        data = json.loads(text_data)
        msg_type = data.get('type')
        msg_data = data.get('data', [])
        if msg_type == "set.game":
            cnt = await self.db_cnt()
            room = await self.get_room()
            if cnt == 1 and room == None:
                setattr(self.RoomList, self.game_group_name, Room())
                room = await self.get_room()
                room.setPlayer({"name": msg_data['player0'], "rating": 0}, {"name": msg_data['player1'], "rating": 0})
            if cnt == 2 and room != None:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        "type" : 'game.message',
                        "data" : {
                            "mode" : "game.start",
                        }
                    }
                )
        if msg_type == 'select.info':
            room = await self.get_room()
            if room.player0.name == msg_data['name']:
                room.player0.fighter = msg_data['select']['player0']
                fighter = msg_data['select']['player0']
            else:
                room.player1.fighter = msg_data['select']['player1']
                fighter = msg_data['select']['player1']
            await self.update_select_info(fighter)
        if msg_type == "set.select":
            cnt = await self.db_cnt()
            room = await self.get_room()
            if cnt == 2:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        "type" : "game.message",
                        "data" : {
                            "mode" : "complete.select",
						}
					}
				)
        if msg_type == "battle.info":
            room = await self.get_room()
            if room.player0.name == msg_data['name']:
                room.player0.character.updateInfo(msg_data['x'], msg_data['y'], msg_data['state'], msg_data['health'])
            else:
                room.player1.character.updateInfo(msg_data['x'], msg_data['y'], msg_data['state'], msg_data['health'])
            await self.update_battle_info({"x" : msg_data['x'], "y" : msg_data['y'], "state" : msg_data['state'], "health" : msg_data['health']})  
        if msg_type == "battle.complete":
            cnt = await self.db_cnt()
            room = await self.get_room()
            if room.winner == "":
                room.winner = msg_data['winner']
                await self.calculate_rating()
            if cnt == 2:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        "type" : "game.message",
                        "data" : {
                            "mode" : "complete.battle",
                        }
                    }
                )
        if msg_type == "result.complete":
            cnt = await self.db_cnt()
            room = await self.get_room()
            if cnt == 2:
                await self.channel_layer.group_send(
                    self.game_group_name, {
                        "type" : "game.message",
                        "data" : {
                            "mode" : "complete.result",
                        }
                    }
                )
        if msg_type == "game.clear":
           await self.disconnect(1001)

    async def join_matching(self):
        flag = False
        while flag == False:
            count = await self.get_room_cnt()
            name = await self.get_room_name()
            if count == 0 or name == "not":
                await self.create_room()
                await self.channel_layer.group_add(self.game_group_name, self.channel_name)
                await self.channel_layer.group_discard("game_queue", self.channel_name)
                flag = True
            else:
                if name != "not":
                    self.game_group_name = name
                    if await self.rating_check(name):
                        await self.channel_layer.group_add(self.game_group_name, self.channel_name)
                        await self.channel_layer.group_discard("game_queue", self.channel_name)
                        await self.set_player(1)
                        player = await self.get_player()
                        await self.channel_layer.group_send(
                            self.game_group_name, {
                                "type" : 'game.message',
                                "data" : {
                                    "mode" : "set.game",
                                    "player0" : player["player0"],
                                    "player0display" : player["player0display"],
                                    "player1" : player["player1"],
                                    "player1display" : player["player1display"],
                                    "group" : self.game_group_name,
                                }
                            }
                        )
                        flag = True
                    else:
                        self.group_depart()
                    self.rating_difference += 200
    
    async def get_room(self):
        return getattr(self.RoomList, self.game_group_name, None)

    async def update_select_info(self, fighter):
        await self.channel_layer.group_send(
            self.game_group_name, {
                "type" : 'game.message',
                "data" : {
                    "mode" : "update.select",
                    "name" : self.user_name,
                    "fighter" : fighter,
                }
            }
        )
    
    async def update_battle_info(self, info):
        await self.channel_layer.group_send(
            self.game_group_name, {
                "type" : "game.message",
                "data" : {
                    "mode" : "update.battle",
                    "name" : self.user_name,
                    "x" : info["x"],
                    "y" : info["y"],
                    "state" : info["state"],
                    "health" : info["health"],
                }
            }
        )

    async def get_group_member_count(self, group_name):
        channel_layer = get_channel_layer()
        group_info = await channel_layer.group_layer.group_status(group_name)
        if group_info:
            return len(group_info['channel_names'])
        else:
            return -1

    async def game_message(self, event):
        await self.send(text_data=json.dumps(event))
    
    async def calculate_rating(self):
        is_room = getattr(self.RoomList, self.game_group_name, None)
        ratingInfo = await self.get_rating_all([is_room.player0.name, is_room.player1.name])
        if is_room.winner == is_room.player0.name:
            player0rating = rating_calculator(ratingInfo[0], ratingInfo[1], 0)
            player1rating = rating_calculator(ratingInfo[1], ratingInfo[0], 1)
        else:
            player0rating = rating_calculator(ratingInfo[0], ratingInfo[1], 1)
            player1rating = rating_calculator(ratingInfo[1], ratingInfo[0], 0)
        await self.set_rating([is_room.player0.name, player0rating], [is_room.player1.name, player1rating], is_room.winner)


    @database_sync_to_async
    def get_rating_all(self, player):
        ratings = []

        for user in player:
            is_user = User.objects.get(username=user)
            rating = UserRecordFightingGame.objects.get(me=is_user)
            ratings.append(rating.rating)
        return ratings

    @database_sync_to_async
    def db_cnt(self):
        is_room = GameRoom.objects.get(room_name=self.game_group_name)
        cnt = is_room.cnt
        cnt += 1
        if cnt < 2:
            is_room.cnt = cnt
        else:
            is_room.cnt = 0
        is_room.save()
        return cnt
    
    @database_sync_to_async
    def group_depart(self):
        is_room = GameRoom.objects.get(room_name=self.game_group_name)
        is_room.status = "waiting"
        is_room.save()
        self.game_group_name = ""

    @database_sync_to_async
    def get_room_cnt(self):
        return GameRoom.objects.count()
    
    @database_sync_to_async
    def get_display_name(self):
        is_user = User.objects.get(username=self.user_name)
        return is_user.display_name
    
    @database_sync_to_async
    def create_room(self):
        self.game_group_name = self.user_name + random_key(6)
        is_room = GameRoom(room_name=self.game_group_name, status="waiting", player0=self.user_name, player0displayName=self.display_name)
        is_room.save()
    
    @database_sync_to_async
    def get_room_name(self):
        room_all = GameRoom.objects.all()
        for room in room_all:
            if room.status == "waiting":
                room.status = "playing"
                room.save()
                return room.room_name
        return "not"
    
    @database_sync_to_async
    def set_player(self, player_num):
        is_room = GameRoom.objects.get(room_name=self.game_group_name)
        if player_num == 0:
            is_room.player0 = self.user_name
            is_room.player0displayName = self.display_name
        else:
            is_room.player1 = self.user_name
            is_room.player1displayName = self.display_name
        is_room.save()
    
    @database_sync_to_async
    def get_player(self):
        is_room = GameRoom.objects.get(room_name=self.game_group_name)
        return {"player0": is_room.player0, "player0display" : is_room.player0displayName, "player1": is_room.player1, "player1display" : is_room.player1displayName}

    @database_sync_to_async
    def db_delete(self):
        is_room = GameRoom.objects.get(room_name=self.game_group_name)
        is_room.delete()
    
    @database_sync_to_async
    def get_rating(self, name):
        is_user = User.objects.get(username=name)
        record = UserRecordFightingGame.objects.get(me=is_user)
        return record.rating

    @database_sync_to_async
    def rating_check(self, group_name):
        is_room = GameRoom.objects.get(room_name=group_name)
        if is_room.player0rating > self.rating + self.rating_difference or is_room.player0rating < self.rating - self.rating_difference:
            return False
        return True
    
    @database_sync_to_async
    def set_rating(self, player0Info, player1Info, winner):
        player0 = User.objects.get(username=player0Info[0])
        player0record = UserRecordFightingGame.objects.get(me=player0)
        player1 = User.objects.get(username=player1Info[0])
        player1record = UserRecordFightingGame.objects.get(me=player1)
        player0record.rating = player0Info[1]
        player1record.rating = player1Info[1]
        if winner == player0.username:
            player0record.win += 1
            player1record.lose += 1
        else:
            player1record.win += 1
            player0record.lose += 1
        player0record.save()
        player1record.save()

