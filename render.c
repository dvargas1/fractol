/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:26:15 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/06 08:21:09 by dvargas          ###   ########.fr       */
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


double ft_magic(t_data *data, double pr, double pi)
{
	double ret;

	ret = 0;
	if (ft_strcmp(data->fname,"mandelbrot") == 0)
		ret = mandelbrotset(pr, pi);
	else if(ft_strcmp(data->fname,"julia") == 0)
		ret = juliaset(data, pr, pi);
	else if (ft_strcmp(data->fname,"tricorn") == 0)
		ret = tricornset(pr, pi);
		
	return(ret);
}


void	ft_render(t_data *data)
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
			pr = data->minR + (double)x * (data->maxR - data->minR) / WINDOW_WIDTH;
			pi = data->maxI + (double)y * (data->minI - data->maxI) / WINDOW_HEIGHT;	
			color = ft_magic(data, pr, pi);
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
