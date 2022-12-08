/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:44:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/08 08:16:20 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		neg;
	double	div;

    i = 0;
	nb = 0;
	div = 0.1;
	neg = 1;
	while(str[i] == '+' || ft_isspace(str[i]) || str[i] == '-')
    {
        if (str[i] == '-')
            neg = -1;
        i++;
    }
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (nb * neg);
}
