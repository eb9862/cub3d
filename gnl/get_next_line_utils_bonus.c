/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:51:14 by eunhwang          #+#    #+#             */
/*   Updated: 2024/06/11 17:17:46 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define TOTAL_LEN 0
#define S1_LEN 1

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;
	size_t	i;

	l = 0;
	while (*((char *)src + l) != '\0')
		l++;
	if (size == 0)
		return (l);
	i = 0;
	while (*((char *)src + i) != '\0' && i + 1 < size)
	{
		*(dst + i) = *((char *)src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (l);
}

size_t	gnl_strlen(const char *s)
{
	size_t	l;

	if (s == NULL)
		return (0);
	l = 0;
	while (*(s + l) != '\0')
		l++;
	return (l);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len[2];
	size_t		i[2];

	len[TOTAL_LEN] = gnl_strlen((char *)s1) + gnl_strlen((char *)s2);
	res = (char *)malloc(sizeof(char) * (len[TOTAL_LEN] + 1));
	if (res == NULL)
		return (0);
	i[0] = 0;
	i[1] = 0;
	len[S1_LEN] = gnl_strlen((char *)s1);
	while (i[0] < len[TOTAL_LEN])
	{
		if (i[0] < len[S1_LEN])
			*(res + i[0]) = *(s1 + i[0]);
		else
		{
			*(res + i[0]) = *(s2 + i[1]);
			i[1]++;
		}
		i[0]++;
	}
	*(res + i[0]) = '\0';
	free((char *)s1);
	return (res);
}
