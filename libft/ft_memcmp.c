/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:35:31 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 10:33:33 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		res;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
		{
			res = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
			return (res);
		}
		i++;
	}
	i--;
	res = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (res);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "abcde";
	char *s2 = "axc";
	//s2 = "abcde";
	size_t n = 3;
	printf("%d", memcmp(s1, s2, n));
	printf(" %d\n", ft_memcmp(s1, s2, n));
}*/
