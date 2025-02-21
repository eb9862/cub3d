/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:35:40 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 11:06:19 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*p;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			p = (void *)s + i;
			return (p);
		}
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "enb832";
	int c = 8+'0';
	unsigned int n = 4;
	char *res1;
	char *res2;
	res1 = (char *)memchr(s, c, n);
	res2 = (char *)ft_memchr(s, c, n);
	printf("%s %s\n", res1, res2);
}*/