/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/02 09:36:46 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixelput(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;

}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int handle_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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

double	mandelb(double cr, double ci)
{
	double i = 0;
	double zr = 0;
	double zi = 0;
	double tmp = 0;

	while(i < MAX_ITERATION)
	{
		if((zr * zr + zi * zi) > 4.0)
			break;
		tmp = 2 * zr * zi +ci;
		zr = sqrt(zr) - sqrt(zi) + cr;
		zi = tmp;
		i++;
	}
	return(i);
/*
	i = 0;
	z2.x = 0;
	z2.y = 0;
	while ((i < MAX_ITERATION) && ((z2.x + z2.y) < 4))
	{
		frac.zi = 2.0 * frac.zr * frac.zi + constant.x;
		frac.zr = sqrt(z2.x) - sqrt(z2.y) + constant.y;
		z2.x = frac.zr * frac.zr;
		z2.y = frac.zi * frac.zi;
		i++;
	}
	if (i == MAX_ITERATION)
		return (MAX_ITERATION);
	return (i);
	*/
}

void test_init(t_fractol frac)
{
	frac.minR = -2.0;
	frac.maxR = 1.0;
	frac.minI = frac.maxI + (frac.maxR - frac.minR) * WINDOW_HEIGHT / WINDOW_WIDTH;
	frac.maxI = -1.5;
	frac.zi = 0;
	frac.zr = 0;
	frac.buf = NULL;
}

void	set_pixel_color(t_data *data, int x, int y, int color)
{
		data->img.addr[x * 4 + y * WINDOW_WIDTH * 4] = color;
		data->img->addr[x * 4 + y * WINDOW_WIDTH * 4 + 1] = color >> 8;
		data->img->addr[x * 4 + y * WINDOW_WIDTH * 4 + 2] = color >> 16;
		data->img->addr[x * 4 + y * WINDOW_WIDTH * 4 + 3] = color >> 24;
}

void	ft_render(t_data data, t_fractol frac)
{
	double x = 0.0;
	double y = 0.0;
	double pr;
	double pi;
	double color;

	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pr = frac.minR + x * (frac.maxR - frac.minR) / WINDOW_WIDTH;
			pi = frac.maxI + y * (frac.minI - frac.maxI) / WINDOW_HEIGHT;	
			color = mandelb(pr, pi);
			set_pixel_color(&data, x, y, color);
			/*
			if (color == MAX_ITERATION)
				my_mlx_pixelput(&img, x, y, create_trgb(0, 0, 0, 0));
			else
			{
				color = (color * 255 / MAX_ITERATION) * 12 * 35;
				my_mlx_pixelput(&img, x, y, create_trgb(0, color, 0, 255));
			}
			*/
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);
}

int main(void)
{
	t_data data;
	t_fractol frac;

	test_init(frac);

	if((data.mlx_ptr = mlx_init()) == NULL)
		return 1;
	if((data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol")) == NULL)
	{
		free(data.win_ptr);
		return 1;
	}
	data.img.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	ft_render(data, frac);
	
//	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,&data);


	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
