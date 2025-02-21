/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:35:51 by eunhwang          #+#    #+#             */
/*   Updated: 2024/06/11 21:59:14 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	abs(int i)
{
	if (i > 0)
		return (i);
	else
		return (i *(-1));
}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (*(s1 + i) != '\0' && *(s2 + i) != '\0'))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		if (i == n - 1)
			break ;
		i++;
	}
	res = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (res);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	char s1[] = "test\200";
	char s2[] = "test\0";
	//char s1[] = "abcdefgh";
	//char s2[] = "abcdwxyz";
	//s1[2] = 0;
	//s2[2] = 0;
	int r1 = strncmp(s1, s2, 6);
	int r2 = ft_strncmp(s1, s2, 6);
	printf("%d %d\n", s1[4], s2[4]);
	printf("%d %d\n", r1, r2);
}*/
