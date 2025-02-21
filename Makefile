CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = cub3D

HEADER = cub.h

DIR_GNL = gnl

DIR_LIBFT = libft

DIR_MLX = minilibx

SRCS = hook.c\
		main.c\
		utils.c\
		player.c\
		map.c

# SRCS = test.c

OBJS = $(SRCS:.c=.o)

MAKE = make

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(DIR_LIBFT) all
	$(MAKE) -C $(DIR_GNL) all
	$(MAKE) -C $(DIR_MLX) all
	$(CC) $(CFLAGS) $^ -o $(NAME) -lm -lft -L $(DIR_LIBFT) -lgnl -L $(DIR_GNL) -lmlx -L $(DIR_MLX) -framework OpenGL -framework Appkit

# $(CC) $(CFLAGS) $^ -o $(NAME) -lm -lft -L $(DIR_LIBFT) -lgnl -L $(DIR_GNL) -lmlx -lXext -lX11 -L $(DIR_MLX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	$(MAKE) -C $(DIR_LIBFT) clean
	$(MAKE) -C $(DIR_GNL) clean
	$(MAKE) -C $(DIR_MLX) clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(MAKE) -C $(DIR_GNL) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
