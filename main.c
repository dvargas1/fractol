/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/07 07:56:27 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_zoom(t_data *data, double zoom)
{
	double centerR;
	double centerI;

	centerR = data->minR - data->maxR;
	centerI = data->maxI - data->minI;
	data->maxR = data->maxR + (centerR - zoom * centerR) / 2;
	data->minR = data->maxR + zoom * centerR;
	data->minI = data->minI + (centerI - zoom * centerI) / 2;
	data->maxI = data->minI + zoom * centerI;
}

static void	ft_move(t_data *data, double distance, char direction)
{
	double	centerR;
	double	centerI;

	centerR = data->minI - data->minR;
	centerI = data->maxR - data->minI;
	if (direction == 'R')
	{
		data->minR += centerR * distance;
		data->maxR += centerR * distance;
	}
	else if (direction == 'L')
	{
		data->minR -= centerR * distance;
		data->maxR -= centerR * distance;
	}
	else if (direction == 'D')
	{
		data->minI -= centerI * distance;
		data->maxI -= centerI * distance;
	}
	else if (direction == 'U')
	{
		data->minI += centerI * distance;
		data->maxI += centerI * distance;
	}
}

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
		endgame(data);
	
	else if(keysym == XK_c)
		ft_zoom(data, 0.5);
	else if(keysym == XK_space)
		ft_zoom(data, 2);
	else if(keysym == XK_Up)
		ft_move(data, 0.02, 'U');
	else if(keysym == XK_Down)
		ft_move(data, 0.02, 'D');
	else if(keysym == XK_Left)
		ft_move(data, 0.02, 'L');
	else if(keysym == XK_Right)
		ft_move(data, 0.02, 'R');
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
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,&data);
	mlx_loop(data.mlx_ptr);
}

//lidar com os hooks pedidos no mandatorio
//organizar melhor os codigos 
