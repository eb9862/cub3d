/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:18:36 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/07 14:09:54 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dst == NULL)
		dst_len = 0;
	else
		dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (dst_len + 1 > size)
		return (src_len + size);
	if (dst_len + 1 < size)
	{
		while (*((char *)src + i) != '\0' && i + dst_len + 1 < size)
		{
			*(dst + dst_len + i) = *((char *)src + i);
			i++;
		}
	}
	*(dst + dst_len + i) = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char dest[] = "rrrrrrrrrrrrrrr";
	//char src[0xF] = "nyan !";
	//char *dest = "abcdefg";
	//char *src = "123";
	//int r1 = strlcat(dest, (void *)0, 0);
	int r2 = ft_strlcat(dest, (void *)0, 0);
	//printf("%d\n", r1);
	printf("%d\n", r2);
	//printf("%lu", count_len((void *)0));
}*/
