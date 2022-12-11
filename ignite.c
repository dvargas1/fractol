/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:28:04 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 08:53:05 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_checkname(t_data *data, char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		name[i] = ft_tolower(name[i]);
		i++;
	}
	if (ft_strcmp(name, "mandelbrot") == 0)
		data->fname = "mandelbrot";
	else if (ft_strcmp(name, "julia") == 0)
		data->fname = "julia";
	else if (ft_strcmp(name, "tricorn") == 0)
		data->fname = "tricorn";
	else
	{
		help();
		endgame(data);
	}
}

void	ft_init(t_data *data, int argc, char **argv)
{
	ft_checkname(data, argv[1]);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->minR = -2.0;
	data->maxR = 1.0;
	data->minI = 2.0;
	data->maxI = -1.5;
	data->colorR = 80;
	data->colorB = 100;
	if (ft_strcmp(data->fname, "julia") == 0)
		ft_preparejulia(data, argc, argv);
}

void	ft_preparejulia(t_data *data, int argc, char **argv)
{
	data->minR = -2.0;
	data->maxR = 2.0;
	data->minI = 2.0;
	data->maxI = -2.0;
	data->juliar = 0;
	data->juliai = 0;
	if (argc == 4)
	{
		data->juliar = ft_atof(argv[2], 0, 1, 0.1);
		data->juliai = ft_atof(argv[3], 0, 1, 0.1);
		if (data->juliar > 2.0 || data->juliar < -2.0)
			helpjulia(data);
		if (data->juliai >= 2.0 || data->juliai <= -2.0)
			helpjulia(data);
	}
}

void	create_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		endgame(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		endgame(data);
	}
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, \
					&data->endian);
}
