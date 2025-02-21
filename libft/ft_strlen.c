/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:58:50 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 11:17:25 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l) != '\0')
		l++;
	return (l);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "1234";
	printf("%lu\n", sizeof(size_t));
	printf("%lu\n", sizeof(unsigned int));
	printf("%lu %lu\n", strlen(s), ft_strlen(s));
	//printf("%d\n", ft_strlen(s));
}*/