/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:55:37 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/26 20:09:55 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	init_direction(t_player *player, t_vars *vars)
// {
// 	int		x;
// 	int		y;

// 	x = player->x;
// 	y = player->y;
// 	if (vars->map[y][x] == 'N')
// 	{
// 		player->dir[0] = 0;
// 		player->dir[1] = -1;
// 	}
// 	else if (vars->map[y][x] == 'E')
// 	{
// 		player->dir[0] = 1;
// 		player->dir[1] = 0;
// 	}
// 	else if (vars->map[y][x] == 'S')
// 	{
// 		player->dir[0] = 0;
// 		player->dir[1] = 1;
// 	}
// 	else if (vars->map[y][x] == 'W')
// 	{
// 		player->dir[0] = -1;
// 		player->dir[1] = 0;
// 	}
// }

void	init_direction(t_player *player, t_vars *vars)
{
	int		x;
	int		y;

	x = player->x;
	y = player->y;
	if (vars->map[y][x] == 'N')
		player->radian = M_PI / 2 * 3;
	else if (vars->map[y][x] == 'E')
		player->radian = 0;
	else if (vars->map[y][x] == 'S')
		player->radian = M_PI / 2;
	else if (vars->map[y][x] == 'W')
		player->radian = M_PI;
}

void	init_player(t_player *player, t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	map = vars->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isalpha(map[y][x]))
			{
				player->x = x;
				player->y = y;
				init_direction(player, vars);
				return ;
			}
			x++;
		}
		y++;
	}
}

// int	rotate_player(int keycode, t_player *player)
// {
// 	double	rotate_speed;
// 	double	dir_x;

// 	rotate_speed = 0.05;
// 	dir_x = player->dir[0];
// 	if (keycode == LEFT)
// 	{
// 		player->dir[0] = player->dir[0] * cos(-rotate_speed) \
// 			- player->dir[1] * sin(-rotate_speed);
// 		player->dir[1] = dir_x * sin(-rotate_speed) \
// 			+ player->dir[1] * cos(-rotate_speed);
// 	}
// 	else if (keycode == RIGHT)
// 	{
// 		player->dir[0] = player->dir[0] * cos(rotate_speed) \
// 			- player->dir[1] * sin(rotate_speed);
// 		player->dir[1] = dir_x * sin(rotate_speed) \
// 			+ player->dir[1] * cos(rotate_speed);
// 	}
// 	return (0);
// }

int	rotate_player(int keycode, t_player *player)
{
	double	rotate_speed;

	rotate_speed = 0.1;
	if (keycode == LEFT)
		player->radian -= rotate_speed;
	else if (keycode == RIGHT)
		player->radian += rotate_speed;

	if (player->radian > 2 * M_PI)
		player->radian = 0;
	else if (player->radian < 0)
		player->radian = 2 * M_PI;
	return (0);
}

// int	move_player(int keycode, t_player *player)
// {
// 	double	speed;
// 	double	vertical_vec[2];

// 	speed = 0.25;
// 	if (keycode == W)
// 	{
// 		player->x += player->dir[0] * speed;
// 		player->y += player->dir[1] * speed;
// 	}
// 	else if (keycode == S)
// 	{
// 		player->x -= player->dir[0] * speed;
// 		player->y -= player->dir[1] * speed;
// 	}
// 	else if (keycode == A)
// 	{
// 		vertical_vec[0] = player->dir[1];
// 		vertical_vec[1] = -player->dir[0];
// 		player->x += vertical_vec[0] * speed;
// 		player->y += vertical_vec[1] * speed;
// 	}
// 	else if (keycode == D)
// 	{
// 		vertical_vec[0] = -player->dir[1];
// 		vertical_vec[1] = player->dir[0];
// 		player->x += vertical_vec[0] * speed;
// 		player->y += vertical_vec[1] * speed;
// 	}
// 	return (0);
// }

int	is_player_collision(double px, double py, t_vars *vars)
{
	int	x;
	int	y;

	px += WALL / 2;
	py += WALL / 2;
	x = (int)(px / WALL);
	y = (int)(py / WALL);

	if (vars->map[y][x] == '1')
		return (1);
	return (0);
}

int	move_player(int keycode, t_vars *vars)
{
	double	speed;
	double	cos_value;
	double	sin_value;
	double	x_to_move = vars->player.x;
	double	y_to_move = vars->player.y;
	t_player	*player = &vars->player;

	cos_value = cos(player->radian);
	sin_value = sin(player->radian);
	speed = 0.25;
	if (keycode == W)
	{
		x_to_move += cos_value * speed;
		y_to_move += sin_value * speed;
	}
	else if (keycode == S)
	{
		x_to_move -= cos_value * speed;
		y_to_move -= sin_value * speed;
	}
	else if (keycode == A)
	{
		x_to_move += sin_value * speed;
		y_to_move -= cos_value * speed;
	}
	else if (keycode == D)
	{
		x_to_move -= sin_value * speed;
		y_to_move += cos_value * speed;
	}
	// 충돌 확인하고 플레이어 위치 업데이트
	if (!is_player_collision(x_to_move * WALL, y_to_move * WALL, vars))
	{
		player->x = x_to_move;
		player->y = y_to_move;
	}
	return (0);
}

void	draw_player(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	size;
	int	px;
	int	py;

	size = 10;
	px = x + (WALL / 2) - (size / 2);
	py = y + (WALL / 2) - (size / 2);
	i = 0;
	while (i < size)
		pixel_to_image(vars, px + (i++), py, color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, px, py + (i++), color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, px + size, py + (i++), color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, px + (i++), py + size, color);
}
