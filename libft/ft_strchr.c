/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:54:49 by dvargas           #+#    #+#             */
/*   Updated: 2022/05/30 14:44:54 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*s;

	s = (char *) str;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}
