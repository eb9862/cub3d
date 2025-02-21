/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:16:24 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/04 16:38:38 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	count_len(char *str)
{
	unsigned int	l;

	l = 0;
	while (*(str + l) != '\0')
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start >= count_len((char *)s))
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	i = 0;
	while (i < len && *((char *)s + start + i) != '\0')
	{
		*(res + i) = *((char *)s + start + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	char *s = "1234567";
	unsigned int start = 3;
	size_t len = 8;

	char *res = ft_substr(s, start, len);
	printf("%s\n", res);
	int i = 0;
	while (*(res + i) != '\0')
		i++;
	printf("%d\n", i);
}*/
