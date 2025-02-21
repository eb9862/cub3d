/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:19:56 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/27 11:00:09 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = b;
	while (i < len)
	{
		*(tmp + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

/*//#include <string.h>
#include <stdio.h>
int main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ft_memset(arr, 0, sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}*/