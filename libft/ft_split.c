/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:53:47 by eunhwang          #+#    #+#             */
/*   Updated: 2024/06/11 17:49:17 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define INDEX 0
#define WORD 1

static int	is_sep(char str_c, char c)
{
	if (str_c == c)
		return (0);
	else
		return (1);
}

static int	count_words(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		while (is_sep(*str, c) == 0)
			str++;
		if (*str != '\0')
			cnt++;
		while (*str != '\0' && is_sep(*str, c) == 1)
			str++;
	}
	return (cnt);
}

static char	*strcat_c(char *s, char chr)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	*(s + i) = chr;
	i++;
	*(s + i) = '\0';
	return (s);
}

static char	**fill_char(char *s, char c, char **res, int word_cnt)
{
	int	i[2];

	i[WORD] = 0;
	while (i[WORD] < word_cnt)
	{
		while (is_sep(*s, c) == 0)
			s++;
		i[INDEX] = 0;
		while (*(s + i[INDEX]) != '\0' && is_sep(*(s + i[INDEX]), c) == 1)
			i[INDEX]++;
		*(res + i[WORD]) = (char *)malloc(sizeof(char) * (i[INDEX] + 1));
		if (*(res + i[WORD]) == NULL)
		{
			i[WORD] = 0;
			while (!*(res + i[WORD]))
				free(*(res + i[WORD]));
			free(res);
			return (0);
		}
		(*(res + i[WORD]))[0] = '\0';
		while (*s != '\0' && is_sep(*s, c) == 1)
			*(res + i[WORD]) = strcat_c(*(res + i[WORD]), *s++);
		i[WORD]++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	char	**res;

	word_cnt = count_words((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (res == NULL)
		return (0);
	res = fill_char((char *)s, c, res, word_cnt);
	if (res != 0)
		res[word_cnt] = 0;
	return (res);
}
