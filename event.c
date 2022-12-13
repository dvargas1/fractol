/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:33:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/13 17:44:08 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_translate(double start, double end, double trans)
{
	return (start + ((end - start) * trans));
}

int	handler_mouse(int keysym, int x, int y, t_data *data)
{
	double	r;
	double	i;
	double	zoom;

	zoom = 0;
	if (keysym == 1 || keysym == 2 || keysym == 3)
		return (0);
	r = (double)x / (WIDTH / (data->maxr - data->minr)) + data->minr;
	i = (double)y / (HEIGHT / (data->maxi - data->mini)) * -1 + data->maxi;
	if (keysym == 4)
		zoom = 0.90;
	else if (keysym == 5)
		zoom = 1.10;
	data->maxi = ft_translate(i, data->maxi, (1.0 * zoom));
	data->maxr = ft_translate(r, data->maxr, (1.0 * zoom));
	data->mini = ft_translate(i, data->mini, (1.0 * zoom));
	data->minr = ft_translate(r, data->minr, (1.0 * zoom));
	ft_render(data);
	return (0);
}

void	handler_arrows(t_data *data, char name)
{
	double	centerr;
	double	centeri;

	centerr = data->maxr - data->minr;
	centeri = data->maxi - data->mini;
	if (name == 'D')
	{
		data->maxi -= centeri * 0.15;
		data->mini -= centeri * 0.15;
	}
	if (name == 'U')
	{
		data->maxi += centeri * 0.15;
		data->mini += centeri * 0.15;
	}
	if (name == 'R')
	{
		data->maxr += centerr * 0.15;
		data->minr += centerr * 0.15;
	}
	if (name == 'L')
	{
		data->maxr -= centerr * 0.15;
		data->minr -= centerr * 0.15;
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
		data->minr = -2.0;
		data->maxr = 2.0;
		data->mini = 2.0;
		data->maxi = -2.0;
		data->juliai = 0.0;
		data->juliar = 0.0;
	}
	if (flag == 4)
		data->colorred += 20;
	if (flag == 5)
		data->colorblue += 20;
}

int	handler_keypress(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
		endgame(data);
	if (keysym == KEY_UP)
		handler_arrows(data, 'U');
	if (keysym == KEY_DOWN)
		handler_arrows(data, 'D');
	if (keysym == KEY_LEFT)
		handler_arrows(data, 'L');
	if (keysym == KEY_RIGHT)
		handler_arrows(data, 'R');
	if (keysym == KEY_R)
		ft_transform(data, 4);
	if (keysym == KEY_B)
		ft_transform(data, 5);
	if (keysym == KEY_Z)
		ft_transform(data, 1);
	if (keysym == KEY_X)
		ft_transform(data, 2);
	if (keysym == KEY_A)
		ft_transform(data, 3);
	ft_render(data);
	return (0);
}
