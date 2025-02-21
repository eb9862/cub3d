CC = cc

CFLAGS = -Wall -Werror -Wextra

HEADER = get_next_line.h

NAME = libgnl.a

SRCS_M = get_next_line.c get_next_line_utils.c

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS_M = $(SRCS_M:.c=.o)

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
