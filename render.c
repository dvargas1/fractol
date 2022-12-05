/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:26:15 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/05 16:03:45 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixelput(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;

}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_render(t_data *data, t_fractol *frac)
{
	int x;
	int y = -1;
	double pr;
	double pi;
	double color;

	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			pr = frac->minR + (double)x * (frac->maxR - frac->minR) / WINDOW_WIDTH;
			pi = frac->maxI + (double)y * (frac->minI - frac->maxI) / WINDOW_HEIGHT;	
			color = juliaset(pr, pi, -0.744, 0.148);
			//color = mandelb(pr, pi);
			if (color == MAX_ITERATION)
				my_mlx_pixelput(data, x, y, create_trgb(0, 0, 0, 0));
			else
			{
				color = (color * 255 / MAX_ITERATION) * 1 * 23;
				my_mlx_pixelput(data, x, y, create_trgb(0, 255, color, 100));
			}
			
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

