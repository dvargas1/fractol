/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/09 23:02:10 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_colorchange(t_data *data, int i, int flag)
{
	if (flag == 1)
		data->colorR += i;
	else if (flag == 2)
		data->colorB += i;
}

void zoom_in(t_data *data)
{
		data->minI /= 1.5;
		data->maxI /= 1.5;
		data->minR /= 1.5;
		data->maxR /= 1.5;
}

void zoom_out(t_data *data)
{
		data->minI *= 1.1;
		data->maxI *= 1.1;
		data->minR *= 1.1;
		data->maxR *= 1.1;
}

void arrows_handler(t_data *data,int flag);

int mouse_handler(int keysym, int x, int y, t_data *data)
{
	if(keysym == 4)
	{
		zoom_in(data);
		x -= WINDOW_WIDTH / 2;
		y -= WINDOW_HEIGHT / 2;
		if(x < 0)
			arrows_handler(data, 3);
		else if(x > 0)
			arrows_handler(data, 4);
		if(y<0)
			arrows_handler(data, 1);
		else if(y> 0)
			arrows_handler(data, 2);
	}
	else if(keysym == 5)
		zoom_out(data);
	ft_render(data);
	return 0;
}

void arrows_handler(t_data *data,int flag)
{
	double	center_r;
	double	center_i;

	center_r = data->maxR - data->minR;
	center_i = data->maxI - data->minI;
	if(flag == 1)
	{
		data->maxI += center_i * 0.1;
		data->minI += center_i * 0.1;
	}
	else if(flag == 2)
	{
		data->maxI -= center_i * 0.1;
		data->minI -= center_i * 0.1;
	}
	else if(flag == 3)
	{
		data->maxR -= center_r * 0.1;
		data->minR -= center_r * 0.1;
	}
	else if(flag == 4)
	{
		data->maxR += center_r * 0.1;
		data->minR += center_r * 0.1;
	}
}

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
		endgame(data);
//	if(keysym == XK_u)
//		ft_zoom(data, 5);
	if(keysym == XK_Up)
		arrows_handler(data, 1);
	if(keysym == XK_Down)
		arrows_handler(data, 2);
	if(keysym == XK_Left)
		arrows_handler(data, 3);
	if(keysym == XK_Right)
		arrows_handler(data, 4);
	if(keysym == XK_r) // R
		ft_colorchange(data, 20, 1);
	if(keysym == XK_b) // B
		ft_colorchange(data, 20, 2);
	ft_render(data);
	return 0;
}

int main(int argc, char **argv)
{
	t_data data;

	if(argc < 2)
		help(&data);
	ft_init(&data, argc, argv);
	create_img(&data);
	ft_render(&data);
	mlx_hook(data.win_ptr, CLOSE_BTN, 0, &endgame, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_mouse_hook (data.win_ptr, mouse_handler, &data);
	mlx_loop(data.mlx_ptr);
}

//organizar melhor os codigos 

//BONUS

// UM FRACTAL A MAIS ---- FEITO
// ZOOM VAI NA DIRECAO DO MOUSE
// MOVER COM SETINHAS 
// MUDAR A COR DO SET ON THE RUN ?
