/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 06:20:06 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 08:05:36 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(t_data *data)
{
	ft_putstr_fd("Welcome to the incredible world of fractals !\n", 1);
	ft_putstr_fd("Today we have 3 types of fractals to show you\n", 1);
	ft_putstr_fd("The incredible MANDELBROT !\n", 1);
	ft_putstr_fd("The astonish TRICORN !\n", 1);
	ft_putstr_fd("The unbelivable JULIA !\n", 1);
	ft_putstr_fd("Just type the fractal name and enjoy the show !\n", 1);
	ft_putstr_fd("You can create yout own JULIA by pressing Z and X also \
					you can press A to reset fractal\n", 1);
	endgame(data);
}

void	helpjulia(t_data *data)
{
	ft_putstr_fd("Sorry we need a value between 2.0 ~ -2.0 to run Julia\n", 1);
	endgame(data);
}

int	endgame(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr && data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
	}
	ft_putstr_fd("Thats all folks\n", 1);
	exit(0);
}

double	ft_atof(char *str, double nb, int neg, double div)
{
	int		i;

	i = 0;
	while (str[i] == '+' || ft_isspace(str[i]) || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (nb * neg);
}
