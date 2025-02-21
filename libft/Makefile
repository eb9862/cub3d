CC = cc

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

NAME = libft.a

SRCS_1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SRCS_2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_M = $(SRCS_1:.c=.o) $(SRCS_2:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef IS_BONUS
	OBJS = $(OBJS_M) $(OBJS_BONUS)
else
	OBJS = $(OBJS_M)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

bonus :
	make IS_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I ./

clean :
	rm -rf $(OBJS_M)
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re so bonus
