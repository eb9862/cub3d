/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:33:07 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/04 16:00:24 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*res;
	size_t		l;
	size_t		i;

	l = ft_strlen((char *)s1);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (0);
	i = 0;
	while (i < l)
	{
		*(res + i) = *((char *)s1 + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "iu is the best korean hip-hop singer";
	char *new1;
	char *new2;

	new1 = strdup(s1);
	new2 = ft_strdup(s1);
	printf("%s | %s\n", new1, new2);
}*/
