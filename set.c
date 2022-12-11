/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:21:31 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 09:16:07 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	juliaset(t_data *data)
{
	double	i;
	double	tmp;
	double	zr;
	double	zi;

	i = 0;
	zr = data->datacr;
	zi = data->dataci;
	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->juliai;
		zr = zr * zr - zi * zi + data->juliar;
		zi = tmp;
		i++;
	}
	return (i);
}

double	mandelbrotset(t_data *data)
{
	double	i;
	double	zr;
	double	zi;
	double	tmp;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->dataci;
		zr = zr * zr - zi * zi + data->datacr;
		zi = tmp;
		i++;
	}
	return (i);
}

double	tricornset(t_data *data)
{
	double	i;
	double	zr;
	double	zi;
	double	tmp;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < MAX_ITERATION)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + data->dataci;
		zr = zr * zr - zi * zi + data->datacr;
		zi = tmp;
		i++;
	}
	return (i);
}
