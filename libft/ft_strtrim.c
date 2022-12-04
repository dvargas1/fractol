/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:00:47 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/06 14:50:37 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
	{
		i++;
	}
	if (set[i] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	j = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_inset(s1[i], set))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (ft_inset(s1[j - 1], set) && i <= j)
		j--;
	trim = ft_substr(s1, i, j - i);
	return (trim);
}
