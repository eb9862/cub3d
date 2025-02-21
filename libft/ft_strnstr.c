/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:35:20 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/04 16:05:20 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_find(char *first, char *find)
{
	size_t	i;
	size_t	n;
	size_t	find_l;

	find_l = ft_strlen((char *)find);
	n = 0;
	i = 0;
	while (n < find_l)
	{
		if (*(first + i) != find[n])
			return (1);
		i++;
		n++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_l;
	size_t	n;
	char	*first;

	find_l = ft_strlen((char *)find);
	if (find_l == 0)
		return ((char *)str);
	if (find_l > len)
		return (NULL);
	n = 0;
	while (n <= len - find_l && *(str + n) != '\0')
	{
		if (*(str + n) == find[0])
		{
			first = (char *)str + n;
			if (check_find(first, (char *)find) == 0)
				return (first);
		}
		n++;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	//char *s1 = "lorem ipsum dolor sit amet";
	//char *s2 = "ipsumm";
	//size_t len = 30;
	//char *res1 = strnstr(s1, s2, len);
	char *res2 = ft_strnstr((void *)0, "fake", 3);
	printf("%s\n", res2);
}*/
