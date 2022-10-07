CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pushswap.a
INCLUDE = ./includes
SRCS = ./mandatory/push_swap.c ./mandatory/push_swap_utils.c \
	   ./circularlinkedlist/clist_clear.c ./circularlinkedlist/clist_error.c \
	   ./circularlinkedlist/clist_init.c ./circularlinkedlist/clist_insert_back.c \
	   ./circularlinkedlist/clist_insert_front.c ./circularlinkedlist/clist_remove.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcsu $@ $^

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re