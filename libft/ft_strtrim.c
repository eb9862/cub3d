/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:41:41 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/29 23:42:23 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*strcat_c(char *dest, char c)
{
	int	i;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	*(dest + i) = c;
	*(dest + i + 1) = '\0';
	return (dest);
}

static int	count_len(char *s1)
{
	int	l;

	l = 0;
	while (*(s1 + l) != '\0')
		l++;
	return (l);
}

static int	is_set(char c, char *set)
{
	int	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l;
	int		r;
	int		i;
	char	*res;

	l = 0;
	r = count_len((char *)s1) - 1;
	while (is_set(*((char *)s1 + l), (char *)set) == 0 && l < r)
		l++;
	while (is_set(*((char *)s1 + r), (char *)set) == 0 && r > 0)
		r--;
	if (r < l)
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) *(r - l + 2));
	if (res == NULL)
		return (0);
	res[0] = '\0';
	i = l;
	while (i >= l && i <= r)
		strcat_c(res, *((char *)s1 + i++));
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	char *s1 = "lorem ipsum dolor sit amet";
	char *set = "te";
	printf("%s\n", ft_strtrim(s1, set));
}*/
