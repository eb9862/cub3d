/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:34:08 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/01 16:17:22 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = 0;
	while (*(s + i) != '\0')
		i++;
	if (c == '\0')
	{
		p = (char *)s + i;
		return (p);
	}
	i--;
	while (i >= 0)
	{
		if (*(s + i) == c)
		{
			p = (char *)s + i;
			return (p);
		}
		i--;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "90374";
	int c = 0;
	printf("%s %s\n", strrchr(s, c), ft_strrchr(s, c));
}*/
