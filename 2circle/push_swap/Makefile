CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
INCS = includes
SRCS = ./mandatory/push_swap.c ./mandatory/push_swap_utils.c \
	   ./mandatory/push_swap_utils2.c ./mandatory/push_swap_operators.c \
	   ./mandatory/merge_sort.c ./mandatory/merge_sort_utils.c \
	   ./mandatory/merge_sort_supplement.c \
	   ./mandatory/merge_sort_below_six.c ./mandatory/rev_merge_sort_below_six.c \
	   ./circularlinkedlist/clist_clear.c ./circularlinkedlist/clist_error.c \
	   ./circularlinkedlist/clist_init.c ./circularlinkedlist/clist_insert_back.c \
	   ./circularlinkedlist/clist_insert_front.c ./circularlinkedlist/clist_remove.c \
	   ./circularlinkedlist/clist_reverse_rotate.c ./circularlinkedlist/clist_rotate.c \
	   ./circularlinkedlist/clist_swap.c \
	   ./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c ./ft_printf/ft_printf_utils2.c \
	   ./ft_printf/ft_printf_utils3.c ./ft_printf/ft_printf_specifier.c \
	   ./ft_printf/ft_printf_specifier2.c \

all : $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(SRCS) $(INCS)
	$(CC) $(CFLAGS) $(SRCS) -I $(INCS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re