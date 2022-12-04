/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:24:25 by dvargas           #+#    #+#             */
/*   Updated: 2022/05/30 14:40:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*space;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	space = malloc (nitems * size);
	if (!space)
		return (NULL);
	ft_bzero (space, nitems * size);
	return (space);
}
