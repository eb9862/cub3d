/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:40:06 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/22 17:20:02 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define X 0
#define Y 1

int	file_check(char *file_name)
{
	int		fd;
	size_t	l;
	char	*s;

	l = ft_strlen(file_name);
	s = ft_substr(file_name, l - 4, 4);
	if (ft_strncmp(s, ".cub", 4) == 0)
		free(s);
	else
	{
		write(2, "Error : This is not cub3d file\n", 31);
		free(s);
		exit(-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(-1);
	}
	return (fd);
}

void	cal_map_size(int fd, int *x, int *y)
{
	char	*line;
	int		l;

	line = get_next_line(fd);
	if (line == NULL)
	{
		write(2, "Error : No data found\n", 22);
		close(fd);
		exit(-1);
	}
	*x = 0;
	*y = 0;
	while (line != NULL)
	{
		l = ft_strlen(line);
		if (*x < l)
			*x = l;
		free(line);
		line = get_next_line(fd);
		(*y)++;
	}
	close(fd);
}

void	init_map(t_vars *vars, char **argv)
{
	int		fd;
	int		i;
	int		j;
	int		l;
	char	*line;
	char	**map;

	fd = open(argv[1], O_RDONLY);

	map = (char **) malloc(sizeof(char *) * (vars->size[Y] + 1));
	if (map == NULL)
		exit(-1);
	i = 0;
	while (i < vars->size[Y])
	{
		map[i] = (char *) malloc(sizeof(char) * vars->size[X]);
		if (map[i] == NULL)
		{
			free_2d(map);
			close(fd);
			exit(-1);
		}
		line = get_next_line(fd);
		l = ft_strlen(line);
		j = 0;
		while (j < vars->size[X])
		{
			if (j < l)
				map[i][j] = line[j];
			else
				map[i][j] = ' ';
			j++;
		}
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
	vars->map = map;
}

void	draw_map(t_vars *vars)
{
	char	**map;
	int		color;
	int		x;
	int		y;

	map = vars->map;
	color = 0xFF00FF;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(vars, x * WALL, y * WALL, color);
			x++;
		}
		y++;
	}
}
