CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INC = includes
SRCS = ./mandatory/push_swap.c ./mandatory/push_swap_utils.c \
	   ./mandatory/push_swap_utils2.c ./mandatory/push_swap_operators.c \
	   ./mandatory/merge_sort.c \
	   ./circularlinkedlist/clist_clear.c ./circularlinkedlist/clist_error.c \
	   ./circularlinkedlist/clist_init.c ./circularlinkedlist/clist_insert_back.c \
	   ./circularlinkedlist/clist_insert_front.c ./circularlinkedlist/clist_remove.c \
	   ./circularlinkedlist/clist_reverse_rotate.c ./circularlinkedlist/clist_rotate.c \
	   ./circularlinkedlist/clist_swap.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcsu $@ $^

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re