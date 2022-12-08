/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/08 08:35:10 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_colorchange(t_data *data, int i, int flag)
{
	if(flag == 1)
		data->colorR += i;
	else if(flag == 2)
		data->colorB +=i;
	else if(flag == 3)
		data->colorG +=i;
}

int ft_zoom(int keysym, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if(keysym == 4)
	{
		data->minI /= 1;
		data->maxI /= 1;
		data->minR /= 1;
		data->maxR /= 1;
	}
	else if(keysym == 5)
	{
		data->minI *= 1;
		data->maxI *= 1;
		data->minR *= 1;
		data->maxR *= 1;
	}
	ft_render(data);
	return 0;
}

/*
void ft_zoom(t_data *data, int i)
{
	data->
}
*/

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == ESC_KEY)
		endgame(data);
	if(keysym == MOUSE_DOWN)
		printf("RODINHA PRA BAIXO");
	if(keysym == KEY_UP)
		printf("UP");
	if(keysym == KEY_DOWN)
		printf("DOWN");
	if(keysym == KEY_LEFT)
		printf("LEFT");
	if(keysym == KEY_RIGHT)
		printf("RIGHT");
	if(keysym == 15) // R
		ft_colorchange(data, 20, 1);
	if(keysym == 11) // B
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
	mlx_mouse_hook (data.win_ptr, ft_zoom, &data);
	mlx_key_hook(data.win_ptr, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
}

//criar os movimentos de zoom mandatorios
//lidar com os hooks pedidos no mandatorio
//organizar melhor os codigos 

//BONUS

// UM FRACTAL A MAIS ---- FEITO
// ZOOM VAI NA DIRECAO DO MOUSE
// MOVER COM SETINHAS 
// MUDAR A COR DO SET ON THE RUN ?
