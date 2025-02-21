/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:06:16 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/23 14:18:18 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (8);
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (8);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	int i = 94;
	while (i < 123)
	{
		int num1 = isalnum(i);
		int num2 = ft_isalnum(i);
		printf("%d %d\n", num1, num2);
		i++;
	}
}*/
