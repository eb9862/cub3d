/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:41:12 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/03 16:15:33 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_size(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

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

static void	ft_itoa_positive(int n, char *res)
{
	char	c;

	if (n == 0)
		return ;
	ft_itoa_positive(n / 10, res);
	c = (n % 10) + '0';
	strcat_c(res, c);
}

static void	ft_itoa_negative(int n, char *res)
{
	char	c;

	if (n == 0)
		return ;
	ft_itoa_negative(n / 10, res);
	c = (n % 10) * (-1) + '0';
	strcat_c(res, c);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;

	size = count_size(n);
	if (n >= 0)
	{
		res = malloc(sizeof(char) * (size + 1));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		if (n == 0)
			strcat_c(res, '0');
		else
			ft_itoa_positive(n, res);
	}
	else
	{
		res = malloc(sizeof(char) * (size + 2));
		if (res == NULL)
			return (NULL);
		res[0] = '-';
		res[1] = '\0';
		ft_itoa_negative(n, res);
	}
	return (res);
}

/*#include <stdio.h>
int main(void)
{
	int n = -2147483648;
	printf("%s\n", ft_itoa(n));
}*/
