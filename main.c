/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/05 07:26:52 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	printf("Keypress: %d\n", keysym);
	return 0;
}
/*
int handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return 0;
}
*/

void test_init(t_fractol *frac)
{
	frac->minR = -2.5;
	frac->maxR = 1.5;
	frac->minI = -2.0;
	frac->maxI = 2.0;
}

int main(void)
{
	t_data data;
	t_fractol frac;

	test_init(&frac);

	if((data.mlx_ptr = mlx_init()) == NULL)
		return 1;
	if((data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol")) == NULL)
	{
		free(data.win_ptr);
		return 1;
	}
	
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	ft_render(&data, &frac);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,&data);


	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
