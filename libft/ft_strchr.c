/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:39:16 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/26 11:39:32 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			p = (char *)s + i;
			return (p);
		}
		i++;
	}
	if (c == '\0')
	{
		p = (char *)s + i;
		return (p);
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "90374";
	int c = 51;
	printf("%s %s\n", strchr(s, c), ft_strchr(s, c));
}*/
