/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:18 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/24 14:36:19 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int c = 68;
	int num1 = tolower(c);
	int num2 = ft_tolower(c);
	printf("%d %d\n", num1, num2);
}*/