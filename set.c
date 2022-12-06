/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:21:31 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/06 08:21:37 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	juliaset(t_data *data, double zr, double zi)
{
	double i = 0;
	double tmp;

	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->ji;
		zr = zr * zr - zi * zi + data->jr;
		zi = tmp;
		i++;
	}
	return(i);
}


double	mandelbrotset(double cr, double ci)
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

double	tricornset(double cr, double ci)
{
	double i = 0;
	double zr = 0;
	double zi = 0;
	double tmp;

	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		i++;
	}
	return(i);
}

