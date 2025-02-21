/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:21:37 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/01 02:20:28 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char src[6] = "abcde";
	char *dst = src + 2;
	size_t n = 3;
	
	char *res1 = memcpy(dst, src, n);
	char *res2 = ft_memcpy(dst, src, n);
	printf("%s\n", res1);
	printf("%s\n", res2);
}*/