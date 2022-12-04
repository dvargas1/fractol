/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:32:39 by dvargas           #+#    #+#             */
/*   Updated: 2022/05/30 14:41:50 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (s < d)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
