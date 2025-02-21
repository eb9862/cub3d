/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:31 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/07 14:09:44 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	full;

	full = size * count;
	if (full == 0)
	{
		res = malloc(0);
		return (res);
	}
	if (full / size != count)
		return (0);
	res = malloc(count * size);
	if (res == NULL)
		return (0);
	ft_memset(res, 0, full);
	return (res);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
	{
		printf("1");
		return (1);
	}
	free(d1);
	free(d2);
	printf("0");
	return (0);
}*/

/*#include <stdio.h>
int main(void)
{
	size_t count = 0;
	char *res1;
	char *res2;
	//int *res3;
	//int *res4;

	res1 = (char *)calloc(count, sizeof(char));
	res2 = (char *)ft_calloc(count, sizeof(char));
	//res3 = (int *)calloc(count, sizeof(int));
	//res4 = (int *)ft_calloc(count, sizeof(int));
	//size_t	i = 0;
	while (i < count)
	{
		printf("%d %d\n", *(res1 + i), *(res2 + i));
		i++;
	}
	while (i < count)
	{
		printf("%d %d\n", *(res3 + i), *(res4 + i));
		i++;
	}
	printf("%s\n%s\n", res1, res2);
}*/
