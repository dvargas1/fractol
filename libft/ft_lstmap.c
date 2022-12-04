/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:03:14 by dvargas           #+#    #+#             */
/*   Updated: 2022/09/06 10:51:14 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	node = ft_lstnew(*f(&lst->content));
	newlist = NULL;
	if (!node)
	{
		ft_lstclear(&newlist, del);
		return (NULL);
	}
	ft_lstadd_back(&newlist, node);
	lst = lst -> next;
	return (newlist);
}
