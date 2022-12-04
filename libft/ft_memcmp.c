/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:15:14 by dvargas           #+#    #+#             */
/*   Updated: 2022/05/30 14:42:21 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
			i++;
			n--;
	}
	return (0);
}
