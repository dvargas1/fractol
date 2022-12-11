/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:26:15 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 09:32:24 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixelput(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	ft_magic(t_data *data)
{
	double	ret;

	ret = 0;
	if (ft_strcmp(data->fname, "mandelbrot") == 0)
		ret = mandelbrotset(data);
	else if (ft_strcmp(data->fname, "julia") == 0)
		ret = juliaset(data);
	else if (ft_strcmp(data->fname, "tricorn") == 0)
		ret = tricornset(data);
	return (ret);
}

void	atributeconstant(t_data *data, int x, int y)
{
	data->datacr = data->minr + (double)x * (data->maxr - data->minr) / WIDTH;
	data->dataci = data->maxi + (double)y * (data->mini - data->maxi) / HEIGHT;
}

void	ft_render(t_data *data)
{
	int		x;
	int		y;
	double	color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			atributeconstant(data, x, y);
			color = ft_magic(data);
			if (color == MAX_ITERATION)
				my_mlx_pixelput(data, x, y, create_trgb(0, 0, 0, 0));
			else
			{
				color = (color * 255 / MAX_ITERATION) * 12;
				my_mlx_pixelput(data, x, y, \
						create_trgb(0, data->colorred, color, data->colorblue));
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
