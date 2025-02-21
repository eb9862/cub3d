/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:55:52 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/29 21:41:15 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define TOTAL_LEN 0
#define S1_LEN 1

static int	count_len(char *str)
{
	int	l;

	l = 0;
	while (*(str + l) != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len[2];
	int		i;
	int		j;

	len[TOTAL_LEN] = count_len((char *)s1) + count_len((char *)s2);
	res = (char *)malloc(sizeof(char) * (len[TOTAL_LEN] + 1));
	if (res == NULL)
		return (0);
	i = 0;
	j = 0;
	len[S1_LEN] = count_len((char *)s1);
	while (i < len[TOTAL_LEN])
	{
		if (i < len[S1_LEN])
			*(res + i) = *(s1 + i);
		else
		{
			*(res + i) = *(s2 + j);
			j++;
		}
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	char *s1 = "abcdef";
	char *s2 = "1234";
	printf("%s\n", ft_strjoin(s1, s2));
}*/
