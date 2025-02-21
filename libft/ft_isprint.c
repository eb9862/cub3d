/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:39:38 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/23 14:45:54 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int i = 32;
	while (i < 129)
	{
		int num1 = isprint(i);
		int num2 = ft_isprint(i);
		printf("%d %d\n", num1, num2);
		i++;
	}
}*/
