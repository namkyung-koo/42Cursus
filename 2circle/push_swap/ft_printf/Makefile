CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = includes
NAME = libftprintf.a
SRCS =	ft_printf.c ft_printf_specifier.c ft_printf_specifier2.c \
		ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c

OBJS = $(SRCS:.c=.o) -I $(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcsu $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re