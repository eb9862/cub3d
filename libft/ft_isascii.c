/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:19:20 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/23 14:37:20 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int num1 = isascii(127);
	int num2 = isascii(127);
	printf("%d\n%d", num1, num2);
}*/
