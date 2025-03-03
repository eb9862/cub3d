/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:02:15 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/26 19:47:44 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"

# define _USE_MATH_DEFINES
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
// # define ESC_KEY 0xff1b
# define ESC_KEY 53

# define WALL 32

typedef struct s_player
{
	double	x;
	double	y;

	// double	dir[2];
	double	radian;

}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;

	t_player	player;
	char		**map;
	int			size[2]; //map_size
}	t_vars;

// hook.c
int		close_window(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
void	reset_image(t_vars *vars);
int		is_reach_wall(double px, double py, t_vars *vars);
double	calculate_distance(double x1, double y1, double x2, double y2);
double	correct_distance(double d, double start_radian, t_vars *vars);
void	draw_ray(t_vars *vars, double start_radian, int x, int color);
int		update_window(t_vars *vars);

// map.c
int		file_check(char *file_name);
void	cal_map_size(int fd, int *x, int *y);
void	init_map(t_vars *vars, char **argv);
void	draw_map(t_vars *vars);

// player.c
void	init_direction(t_player *player, t_vars *vars);
void	init_player(t_player *player, t_vars *vars);
int		rotate_player(int keycode, t_player *player);
int		move_player(int keycode, t_vars *vars);
void	draw_player(t_vars *vars, int x, int y, int color);

// utils.c
void	free_2d(char **s);
void	pixel_to_image(t_vars *vars, int x, int y, int color);
void	draw_square(t_vars *vars, int x, int y, int color);

#endif