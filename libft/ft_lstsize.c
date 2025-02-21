/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:49:20 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/29 17:05:48 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		cnt;

	tmp = lst;
	if (tmp == NULL)
		return (0);
	cnt = 0;
	while (tmp != 0)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
