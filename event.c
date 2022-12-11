/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:33:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 09:16:29 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_translate(double start, double end, double trans)
{
	return (start + ((end - start) * trans));
}

int	mouse_handler(int keysym, int x, int y, t_data *data)
{
	double	r;
	double	i;
	double	zoom;

	zoom = 0;
	if (keysym == 1 || keysym == 2 || keysym == 3)
		return (0);
	r = (double)x / (WIDTH / (data->maxR - data->minR)) + data->minR;
	i = (double)y / (HEIGHT / (data->maxI - data->minI)) * -1 + data->maxI;
	if (keysym == 4)
		zoom = 0.90;
	else if (keysym == 5)
		zoom = 1.10;
	data->maxI = ft_translate(i, data->maxI, (1.0 * zoom));
	data->maxR = ft_translate(r, data->maxR, (1.0 * zoom));
	data->minI = ft_translate(i, data->minI, (1.0 * zoom));
	data->minR = ft_translate(r, data->minR, (1.0 * zoom));
	ft_render(data);
	return (0);
}

void	handler_arrows(t_data *data, char name)
{
	double	center_r;
	double	center_i;

	center_r = data->maxR - data->minR;
	center_i = data->maxI - data->minI;
	if (name == 'D')
	{
		data->maxI -= center_i * 0.15;
		data->minI -= center_i * 0.15;
	}
	if (name == 'U')
	{
		data->maxI += center_i * 0.15;
		data->minI += center_i * 0.15;
	}
	if (name == 'R')
	{
		data->maxR += center_r * 0.15;
		data->minR += center_r * 0.15;
	}
	if (name == 'L')
	{
		data->maxR -= center_r * 0.15;
		data->minR -= center_r * 0.15;
	}
}

void	ft_transform(t_data *data, int flag)
{
	if (flag == 1)
		data->juliai += 0.1;
	if (flag == 2)
		data->juliar += -0.1;
	if (flag == 3)
	{
		data->juliai = 0.0;
		data->juliar = 0.0;
	}
	if (flag == 4)
		data->colorR += 20;
	if (flag == 5)
		data->colorB += 20;
}

int	handler_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		endgame(data);
	if (keysym == XK_Up)
		handler_arrows(data, 'U');
	if (keysym == XK_Down)
		handler_arrows(data, 'D');
	if (keysym == XK_Left)
		handler_arrows(data, 'L');
	if (keysym == XK_Right)
		handler_arrows(data, 'R');
	if (keysym == XK_r)
		ft_transform(data, 4);
	if (keysym == XK_b)
		ft_transform(data, 5);
	if (keysym == XK_z)
		ft_transform(data, 1);
	if (keysym == XK_x)
		ft_transform(data, 2);
	if (keysym == XK_a)
		ft_transform(data, 3);
	ft_render(data);
	return (0);
}
