/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:30:46 by eunhwang          #+#    #+#             */
/*   Updated: 2024/03/04 16:17:18 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_node;
	t_list	*tmp_lst;

	newlst = NULL;
	tmp_lst = lst;
	if (lst == NULL)
		return (0);
	while (tmp_lst != NULL)
	{
		new_node = ft_lstnew(f(tmp_lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			return (0);
		}
		ft_lstadd_back(&newlst, new_node);
		tmp_lst = tmp_lst->next;
	}
	return (newlst);
}
