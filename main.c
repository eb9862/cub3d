/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:04:11 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/16 15:25:20 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_vars(t_vars *vars, char **argv)
{
	init_map(vars, argv);
	init_player(&vars->player, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	vars->img = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);

	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, \
		&vars->size_line, &vars->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_vars	vars;
	int	X = 0, Y = 1;

	if (argc != 2)
	{
		write(2, "Error : Only One Argument Plz\n", 30);
		exit(-1);
	}
	fd = file_check(argv[1]);
	// ~ map validation

	fd = open(argv[1], O_RDONLY);
	cal_map_size(fd, &(vars.size[X]), &(vars.size[Y]));
	printf("map_x : %d\nmap_y : %d\n", vars.size[X], vars.size[Y]);

	init_vars(&vars, argv);

	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);

	mlx_loop_hook(vars.mlx, update_window, &vars);
	mlx_loop(vars.mlx);
}
