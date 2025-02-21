/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:32:05 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/29 21:43:11 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == 32)
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			minus = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		i++;
	}
	return (num * minus);
}

/*#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *str = "+548";
	int num1 = atoi(str);
	int num2 = ft_atoi(str);
	printf("%d %d\n", num1, num2);
}*/
