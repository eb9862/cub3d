/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:44:44 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 10:59:41 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	if (n == 0)
		return ;
	i = 0;
	tmp = s;
	while (i < n)
	{
		*(tmp + i) = 0;
		i++;
	}
}

/*#include <strings.h>
#include <stdio.h>
int main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ft_bzero(arr, sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}*/