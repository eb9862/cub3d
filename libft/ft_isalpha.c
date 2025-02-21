/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:10:40 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/23 13:59:17 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int num1 = isalpha(91);
	int num2 = ft_isalpha(91);
	printf("%d\n%d", num1, num2);
}*/
