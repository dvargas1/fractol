/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvarags@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:16:22 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/08 18:05:07 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbsize(long nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*empty(char *ada)
{
	ada = malloc(2);
	if (!ada)
		return (NULL);
	ada[0] = '0';
	ada[1] = '\0';
	return (ada);
}

char	*ft_itoa(int n)
{
	char	*ada;
	long	i;
	long	nb;

	ada = NULL;
	nb = n;
	i = nbsize(n);
	if (nb == 0)
		return (empty(ada));
	ada = malloc (sizeof(char) * (i + 1));
	if (!ada)
		return (NULL);
	if (nb < 0)
	{
		ada[0] = '-';
		nb *= -1;
	}
	ada[i] = '\0';
	i -= 1;
	while (nb > 0)
	{
		ada[i--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (ada);
}
