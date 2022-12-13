/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 09:23:57 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		help();
	ft_init(&data, argc, argv);
	create_img(&data);
	ft_render(&data);
	mlx_hook(data.win_ptr, CLOSE_BTN, 0, &endgame, &data);
	mlx_key_hook(data.win_ptr, handler_keypress, &data);
	mlx_mouse_hook (data.win_ptr, handler_mouse, &data);
	mlx_loop(data.mlx_ptr);
}
