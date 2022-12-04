/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:04:29 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/04 16:15:42 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!(*lst) && new)
	{
		*lst = new;
		new -> next = NULL;
	}
	else if (lst && new)
	{
		last_node = ft_lstlast(*lst);
		last_node -> next = new;
		new -> next = NULL;
	}	
}
