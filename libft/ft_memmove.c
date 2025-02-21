/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:20:27 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/01 12:37:21 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;
	int	num;

	if (dest == 0 && src == 0)
		return (0);
	num = (int)n;
	if (dest <= src)
	{
		i = 0;
		while (i < num)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		i = num - 1;
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char src[6] = "abcde";
	char *dst = src + 2;
	size_t n = 3;
	
	char *res1 = memmove(dst, src, n);
	//char *res2 = ft_memmove(dst, src, n);
	printf("%s\n", res1);
	//printf("%s\n", res2);
}*/
