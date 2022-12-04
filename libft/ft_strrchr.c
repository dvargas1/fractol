/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:37:10 by dvargas           #+#    #+#             */
/*   Updated: 2022/05/30 14:46:05 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char *) str;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i--;
	}
	return (0);
}
