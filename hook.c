/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:22:56 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/20 17:29:29 by eunhwang         ###   ########.fr       */
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
		move_player(keycode, &vars->player);
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

	x = px / BLOCK;
	y = py / BLOCK;

	if (vars->map[y][x] == '1')
		return (1);
	return (0);
}

void	draw_ray(t_vars *vars, double start_radian)
{
	double	ray_x;
	double	ray_y;
	double	cos_value;
	double	sin_value;

	ray_x = (vars->player.x * SCALE) + (SCALE / 2);
	ray_y = (vars->player.y * SCALE) + (SCALE / 2);
	cos_value = cos(start_radian);
	sin_value = sin(start_radian);
	while (!is_reach_wall(ray_x, ray_y, vars))
	{
		pixel_to_image(vars, ray_x, ray_y, 0xFFFF00);
		ray_x += cos_value;
		ray_y += sin_value;
	}
}

int	update_window(t_vars *vars)
{
	t_player	*player;

	player = &vars->player;
	reset_image(vars);
	draw_map(vars);
	draw_player(vars, player->x * SCALE, player->y * SCALE, 0xFFFFFF);


	double	unit = M_PI / 2 / SCREEN_HEIGHT;
	double	start_radian = vars->player.radian - M_PI / 4;
	int	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		draw_ray(vars, start_radian);
		start_radian += unit;
		i++;
	}


	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
