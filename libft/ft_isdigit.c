/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:59:34 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/23 14:05:09 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int num1 = isdigit(47);
	int num2 = ft_isdigit(47);
	printf("%d\n%d", num1, num2);
}*/
