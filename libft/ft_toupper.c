/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:24 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/24 14:36:26 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int c = 77;
	int num1 = toupper(c);
	int num2 = ft_toupper(c);
	printf("%d %d\n", num1, num2);
}*/