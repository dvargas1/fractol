/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:21:31 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/05 07:25:42 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



double	juliaset(double zr, double zi, double kr, double ki)
{
	double i = 0;
	double tmp;

	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ki;
		zr = zr * zr - zi * zi + kr;
		zi = tmp;
		i++;
	}
	return(i);
}


double	mandelb(double cr, double ci)
{
	double i = 0;
	double zr = 0;
	double zi = 0;
	double tmp;

	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
	return(i);
}

