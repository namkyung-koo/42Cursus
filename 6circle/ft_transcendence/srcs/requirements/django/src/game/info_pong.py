class Window:
	width: int
	height: int
	border: int
	middle: {int, int}

	def __init__(self, width, height, border, middle):
		self.width = width
		self.height = height
		self.border = border
		self.middle = middle

class Player:
	name: str
	rating: int

	def __init__(self, name, rating):
		self.name = name
		self.rating = rating

class Bar:
	x: int
	y: int
	width: int
	height: int
	up: bool
	down: bool

	def __init__(self, width, height, x, y):
		self.width = width
		self.height = height
		self.x = x
		self.y = y
		self.up = False
		self.down = False

	def set_bar(self, x, y):
		self.x = x
		self.y = y
	
	def update(self):
		if self.up == True:
			self.y -= 7
		elif self.down == True:
			self.y += 7

class Score:
	ONE: int
	TWO: int
	WIN: int

	def __init__(self):
		self.ONE = 0
		self.TWO = 0
		self.WIN = 5

	def setScore(self, ONE, TWO):
		self.ONE = ONE
		self.TWO = TWO

class Ball:
	initLoca: {int, int}
	ballX: int
	ballY: int
	radius: int
	velocityX: int
	velocityY: int
	serve: int

	def __init__(self, x1, y1, x2, y2, radius):
		self.ballX = x1
		self.ballY = y1
		self.velocityX = x2
		self.velocityY = y2
		self.radius = radius
		self.serve = 0
		self.initLoca = {x1, y1}

	def set_ball(self, x, y):
		self.ballX = x
		self.ballY = y

	def set_velocity(self, x, y):
		self.velocityX = x
		self.velocityY = y

	def update(self):
		self.ballX += self.velocityX
		self.ballY += self.velocityY
	
	def init(self):
		self.ballX, self.ballY = self.initLoca
		if self.velocityX < 0 and self.velocityX != -6:
			self.velocityX = -6
		elif self.velocityX > 0 and self.velocityX != 6:
			self.velocityX = 6
		if self.velocityY < 0 and self.velocityY != -6:
			self.velocityY = -6
		elif self.velocityY > 0 and self.velocityY != 6:
			self.velocityY = 6

		if self.serve == 2:
			self.velocityX *= -1
			self.velocityY *= -1
			self.serve = 0

class Room:
	mode: str
	status: str # match1, match2, match3
	winner: str
	winner2: str
	winner3 : str
	window: Window
	player0: Player
	player1: Player
	player2: Player
	player3: Player
	player0bar: Bar
	player1bar: Bar
	player2bar: Bar
	player3bar: Bar
	ball: Ball
	score: Score
	frameTime: int
	
	def __init__(self, mode):
		self.winner = ""
		self.winner2 = ""
		self.winner3 = ""
		self.window = Window(1024, 768, 1024 / 50, {1024 / 80, 768})
		self.ball = Ball(1024 / 2, 768 / 2, 6, 6, 1024 / 100)
		self.score = Score()
		self.mode = mode
		self.status = "match1"
		if self.mode == "two":
			self.player0bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50, self.window.height / 4 - self.window.height / 14)
			self.player1bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50, self.window.height / 4 * 3 - self.window.height / 14)
			self.player2bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50 * 48 + 3, self.window.height / 4 - self.window.height / 14)
			self.player3bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50 * 48 + 3, self.window.height / 4 * 3 - self.window.height / 14)
		elif self.mode == "one":
			self.player0bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50, self.window.height / 2 - self.window.height / 14)
			self.player1bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50 * 48 + 3, self.window.height / 2 - self.window.height / 14)	

	def setForNextMatch(self):
		self.score = Score()
		self.window = Window(1024, 768, 1024 / 50, {1024 / 80, 768})
		self.ball = Ball(1024 / 2, 768 / 2, 6, 6, 1024 / 100)
		self.player0bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50, self.window.height / 2 - self.window.height / 14)
		self.player1bar = Bar(self.window.width / 60, self.window.height / 7, self.window.width / 50 * 48 + 3, self.window.height / 2 - self.window.height / 14)

	def setPlayerOneByOne(self, player0, player1):
		self.player0 = Player(player0['name'], player0['rating'])
		self.player1 = Player(player1['name'], player1['rating'])

	def setPlayersTwoByTwo(self, player0, player1, player2, player3):

		players = [player0, player1, player2, player3]

		players_with_rating = [(player, player['rating']) for player in players]

		sorted_players = sorted(players_with_rating, key=lambda x: x[1])

		self.player0 = Player(sorted_players[0][0]['name'], sorted_players[0][0]['rating'])
		self.player1 = Player(sorted_players[3][0]['name'], sorted_players[3][0]['rating'])
		self.player2 = Player(sorted_players[1][0]['name'], sorted_players[1][0]['rating'])
		self.player3 = Player(sorted_players[2][0]['name'], sorted_players[2][0]['rating'])
	
	def setPlayerTournament(self, players):
		self.player0 = Player(players[0], 0)
		self.player1 = Player(players[1], 0)
		self.player2 = Player(players[2], 0)
		self.player3 = Player(players[3], 0)

	def setBarLocation(self, x1, y1, x2, y2):
		self.player0bar.set_bar(x1, y1)
		self.player1bar.set_bar(x2, y2)
	
	def setBallLocation(self, x, y):
		self.ball.set_ball(x, y)
	
	def setBallVelocity(self, x, y):
		self.ball.set_velocity(x, y)
	
	def setScore(self, ONE, TWO):
		self.score.setScore(ONE, TWO)
	
	def setplayer0barState(self, state, value):
		if state == "up":
			self.player0bar.up = value
		if state == "down":
			self.player0bar.down = value
	
	def setplayer1barState(self, state, value):
		if state == "up":
			self.player1bar.up = value
		if state == "down":
			self.player1bar.down = value

	def setplayer2barState(self, state, value):
		if state == "up":
			self.player2bar.up = value
		if state == "down":
			self.player2bar.down = value

	def setplayer3barState(self, state, value):
		if state == "up":
			self.player3bar.up = value
		if state == "down":
			self.player3bar.down = value

	def getHitFactor(self, barMiddlePoint, barHarfHeight):
		return ((barMiddlePoint - self.ball.ballY) / barHarfHeight) * 1.2
	
	def update(self):
		self.player0bar.update()
		self.player1bar.update()
		if self.mode == "two":
			self.player2bar.update()
			self.player3bar.update()
		self.ball.update()
		self.checkWallCollision()
		self.checkBarCollision()
		self.checkBoundary()
		self.checkScore()

	def checkWallCollision(self):
		if (self.ball.ballY + self.ball.velocityY > self.window.height - self.window.border - self.ball.radius) or (self.ball.ballY + self.ball.velocityY < self.window.border + self.ball.radius):
			self.ball.velocityY *= -1.2
		if self.mode == "one":
			if self.player0bar.y < self.window.border:
				self.player0bar.y = self.window.border
			if self.player0bar.y > self.window.height - self.window.border - self.player0bar.height:
				self.player0bar.y = self.window.height - self.window.border - self.player0bar.height
			if self.player1bar.y < self.window.border:
				self.player1bar.y = self.window.border
			if self.player1bar.y > self.window.height - self.window.border - self.player1bar.height:
				self.player1bar.y = self.window.height - self.window.border - self.player1bar.height		
		else:
			if self.player0bar.y < self.window.border:
				self.player0bar.y = self.window.border
			if self.player0bar.y > self.window.height / 2 - self.player0bar.height:
				self.player0bar.y = self.window.height / 2 - self.player0bar.height
			if self.player1bar.y < self.window.height / 2:
				self.player1bar.y = self.window.height / 2
			if self.player1bar.y > self.window.height - self.window.border - self.player1bar.height:
				self.player1bar.y = self.window.height - self.window.border - self.player1bar.height
			if self.player2bar.y < self.window.border:
				self.player2bar.y = self.window.border
			if self.player2bar.y > self.window.height / 2 - self.player2bar.height:
				self.player2bar.y = self.window.height / 2 - self.player2bar.height
			if self.player3bar.y < self.window.height / 2:
				self.player3bar.y = self.window.height / 2
			if self.player3bar.y > self.window.height - self.window.border - self.player3bar.height:
				self.player3bar.y = self.window.height - self.window.border - self.player3bar.height

	def checkBarCollision(self):
		if self.mode == "one":
			if self.ball.ballX - self.ball.radius < self.player0bar.x + 10 and self.ball.ballY + self.ball.velocityY >= self.player0bar.y and self.ball.ballY + self.ball.velocityY <= self.player0bar.y + self.player0bar.height:
				dir = self.getHitFactor(self.player0bar.y + self.player0bar.height / 2, self.player0bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir
			if self.ball.ballX + self.ball.radius > self.player1bar.x + self.player1bar.width - 10 and self.ball.ballY + self.ball.velocityY >= self.player1bar.y and self.ball.ballY + self.ball.velocityY <= self.player1bar.y + self.player1bar.height:
				dir = self.getHitFactor(self.player1bar.y + self.player1bar.height / 2, self.player1bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir
		if self.mode == "two":
			if self.ball.ballX - self.ball.radius < self.player0bar.x + 10 and self.ball.ballY + self.ball.velocityY >= self.player0bar.y and self.ball.ballY + self.ball.velocityY <= self.player0bar.y + self.player0bar.height:
				dir = self.getHitFactor(self.player0bar.y + self.player0bar.height / 2, self.player0bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir
			if self.ball.ballX - self.ball.radius < self.player1bar.x + 10 and self.ball.ballY + self.ball.velocityY >= self.player1bar.y and self.ball.ballY + self.ball.velocityY <= self.player1bar.y + self.player1bar.height:
				dir = self.getHitFactor(self.player1bar.y + self.player1bar.height / 2, self.player1bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir
			if self.ball.ballX + self.ball.radius > self.player2bar.x + self.player2bar.width - 10 and self.ball.ballY + self.ball.velocityY >= self.player2bar.y and self.ball.ballY + self.ball.velocityY <= self.player2bar.y + self.player2bar.height:
				dir = self.getHitFactor(self.player2bar.y + self.player2bar.height / 2, self.player2bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir
			if self.ball.ballX + self.ball.radius > self.player3bar.x + self.player3bar.width - 10 and self.ball.ballY + self.ball.velocityY >= self.player3bar.y and self.ball.ballY + self.ball.velocityY <= self.player3bar.y + self.player3bar.height:
				dir = self.getHitFactor(self.player3bar.y + self.player3bar.height / 2, self.player3bar.height / 2)
				self.ball.velocityX *= -1.2
				self.ball.velocityY *= dir

	def checkBoundary(self):
		if self.mode == "two":
			if self.ball.ballX < self.player0bar.x:
				self.ball.serve += 1
				self.ball.init()
				self.score.TWO += 1
			elif self.ball.ballX > self.player2bar.x + self.player2bar.width:
				self.ball.serve += 1
				self.ball.init()
				self.score.ONE += 1
		else:
			if self.ball.ballX < self.player0bar.x:
				self.ball.serve += 1
				self.ball.init()
				self.score.TWO += 1
			elif self.ball.ballX > self.player1bar.x + self.player1bar.width:
				self.ball.serve += 1
				self.ball.init()
				self.score.ONE += 1

	def checkScore(self):
		if self.score.ONE == self.score.TWO and self.score.ONE > self.score.WIN - 2:
			self.score.WIN = self.score.ONE + 2
		if self.mode == "one" and self.status == "match1":
			if self.score.ONE > self.score.TWO and self.score.ONE == self.score.WIN:
				self.winner = self.player0.name
			elif self.score.ONE < self.score.TWO and self.score.TWO == self.score.WIN:
				self.winner = self.player1.name
		elif self.mode == "one" and self.status == "match2":
			if self.score.ONE > self.score.TWO and self.score.ONE == self.score.WIN:
				self.winner2 = self.player2.name
			elif self.score.ONE < self.score.TWO and self.score.TWO == self.score.WIN:
				self.winner2 = self.player3.name
		elif self.mode == "one" and self.status == "match3":
			if self.score.ONE > self.score.TWO and self.score.ONE == self.score.WIN:
				self.winner3 = self.winner
			elif self.score.ONE < self.score.TWO and self.score.TWO == self.score.WIN:
				self.winner3 = self.winner2
		elif self.mode == "two":
			if self.score.ONE > self.score.TWO and self.score.ONE == self.score.WIN:
				self.winner = self.player0.name
				self.winner2 = self.player1.name
			elif self.score.TWO > self.score.ONE and self.score.TWO == self.score.WIN:
				self.winner = self.player2.name
				self.winner2 = self.player3.name