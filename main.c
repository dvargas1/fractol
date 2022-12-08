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

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == ESC_KEY)
		endgame(data);
	if(keysym == MOUSE_UP)
		printf("RODINHA PRA CIMA");
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
