CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=do_op.c ft_op.c
OBJS=$(SRCS:.c=.o)
NAME=do-op

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
