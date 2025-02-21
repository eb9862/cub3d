/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:49:58 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/04 16:17:15 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	int				len;

	len = ft_strlen((char *)s);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	i = 0;
	while (*((char *)s + i) != '\0')
	{
		*(res + i) = f(i, *((char *)s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	
}*/
