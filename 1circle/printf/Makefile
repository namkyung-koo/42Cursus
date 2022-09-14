CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCLUDE = ./mandatory/ft_printf.h ./bonus/ft_printf_bonus.h
SRCS =	./mandatory/ft_printf.c ./mandatory/ft_printf_specifier.c ./mandatory/ft_printf_specifier2.c \
		./mandatory/ft_printf_utils.c ./mandatory/ft_printf_utils2.c ./mandatory/ft_printf_utils3.c

SRCS_BONUS = ./bonus/ft_printf_bonus.c ./bonus/ft_printf_specifier_bonus.c \
			 ./bonus/ft_printf_specifier2_bonus.c ./bonus/ft_printf_utils_bonus.c \
			 ./bonus/ft_printf_utils2_bonus.c ./bonus/ft_printf_utils3_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

TO_COMPILE = $(if $(filter bonus, $(MAKECMDGOALS)), $(OBJS_BONUS), $(OBJS))

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(TO_COMPILE)
	ar -rcsu $@ $^

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus