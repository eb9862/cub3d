/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:15:31 by eunhwang          #+#    #+#             */
/*   Updated: 2025/02/16 14:23:44 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_2d(char **s)
{
	int	n;

	n = 0;
	while (*(s + n) != NULL && *(s + n) != 0)
	{
		free(s[n]);
		n++;
	}
	free(s);
}

void	pixel_to_image(t_vars *vars, int x, int y, int color)
{
	char	*loc;

	if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT || x < 0 || y < 0)
		return ;

	loc = vars->addr + (y * vars->size_line + x * (vars->bpp / 8));
	*(unsigned int *)loc = color;
}

void	draw_square(t_vars *vars, int x, int y, int color)
{
	int	i;
	int	size;

	size = BLOCK;
	i = 0;
	while (i < size)
		pixel_to_image(vars, x + (i++), y, color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, x, y + (i++), color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, x + size, y + (i++), color);
	i = 0;
	while (i < size)
		pixel_to_image(vars, x + (i++), y + size, color);
}
