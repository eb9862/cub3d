/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:22:56 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/26 20:11:02 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	//mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, vars);
	if (keycode == LEFT || keycode == RIGHT)
		rotate_player(keycode, &vars->player);
	return (0);
}

void	reset_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, \
		&vars->size_line, &vars->endian);
}

int	is_reach_wall(double px, double py, t_vars *vars)
{
	int	x;
	int	y;

	x = (int)(px / WALL);
	y = (int)(py / WALL);

	if (vars->map[y][x] == '1')
		return (1);
	return (0);
}

double	calculate_distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);

	return (sqrt(dx * dx + dy * dy));
}

double	correct_distance(double	d, double start_radian, t_vars *vars)
{
	if (d < 0.1)
		d = 0.1;
	else if (d > SCREEN_HEIGHT)
		d = SCREEN_HEIGHT;
	d *= cos(start_radian - vars->player.radian);
	return (d);
}

void	draw_ray(t_vars *vars, double start_radian, int x, int color)
{
	double	ray_x;
	double	ray_y;
	double	cos_value;
	double	sin_value;

	ray_x = (vars->player.x * WALL) + (WALL / 2);
	ray_y = (vars->player.y * WALL) + (WALL / 2);
	cos_value = cos(start_radian);
	sin_value = sin(start_radian);
	while (!is_reach_wall(ray_x, ray_y, vars))
	{
		pixel_to_image(vars, ray_x, ray_y, color);
		ray_x += cos_value;
		ray_y += sin_value;
	}


	ray_x -= cos_value;
	ray_y -= sin_value;

	int px = vars->player.x * WALL + (WALL / 2);
	int py = vars->player.y * WALL + (WALL / 2);

	double	d = calculate_distance(ray_x, ray_y, px, py);
	d = correct_distance(d, start_radian, vars);
	double	h = SCREEN_HEIGHT * WALL / (d + 0.0001);
	int	start_y = (SCREEN_HEIGHT / 2) - (h / 2);
	int	end = start_y + h;
	while (start_y < end)
	{
		pixel_to_image(vars, x, start_y, 0x40E0D0);
		start_y++;
	}
}

int	update_window(t_vars *vars)
{
	t_player	*player;

	player = &vars->player;
	reset_image(vars);
	draw_map(vars);
	draw_player(vars, player->x * WALL, player->y * WALL, 0xFFFFFF);

	double	unit = M_PI / 3 / SCREEN_WIDTH;
	double	start_radian = vars->player.radian - M_PI / 6;
	int	i = 0;
	while (i < SCREEN_WIDTH)
	{
		draw_ray(vars, start_radian, i, 0xFFFF00);
		start_radian += unit;
		i++;
	}
	draw_ray(vars, player->radian, i, 255);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
