/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:33:47 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 14:05:19 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = 0;
	while (*((char *)src + l) != '\0')
		l++;
	if (size == 0)
		return (l);
	i = 0;
	while (*((char *)src + i) != '\0' && i < size - 1)
	{
		*(dst + i) = *((char *)src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (l);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
    //char *dst = "abcde";
    //char *src = "1234";
	char dst[] = "abcde";
    char src[] = "1234";
    size_t size = 9;
    printf("%lu\n", ft_strlcpy(dst, src, size));
}*/