CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h ft_printf.h
SRCS = 	ft_atoi.c  ft_bzero.c   ft_calloc.c     \
		ft_isalnum.c ft_isalpha.c ft_isascii.c  \
		ft_isdigit.c ft_isprint.c ft_memchr.c   \
		ft_memcmp.c  ft_memcpy.c  ft_memmove.c  \
		ft_memset.c  ft_strchr.c  ft_strdup.c   \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c  \
		ft_strlen.c  ft_strncmp.c ft_strnstr.c  \
		ft_strrchr.c ft_substr.c  ft_tolower.c  \
		ft_toupper.c ft_strtrim.c ft_split.c    \
		ft_itoa.c    ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c          \
		ft_putendl_fd.c ft_putnbr_fd.c          \
		get_next_line.c \
		ft_printf.c \
		ft_printf_specifier.c ft_printf_specifier2.c \
		ft_printf_utils.c ft_printf_utils2.c

SRCS_BOUNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c   \
			 ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c    \
			 ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BOUNS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADER)
	@ar rcsu $@ $^

clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)

bonus :
	@make WITH_BONUS=1 all

fclean : clean
	@$(RM) $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re bonus