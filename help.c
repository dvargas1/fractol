/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 06:20:06 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/13 17:28:13 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_putstr_fd("\e[1;37m=========================================\e[0m\n", 1);
	ft_putstr_fd("Welcome to the incredible world of fractals !\n", 1);
	ft_putstr_fd("Today we have 3 types of fractals to show you\n", 1);
	ft_putstr_fd("     \e[41mThe incredible MANDELBROT !\e[0m\n", 1);
	ft_putstr_fd("     \e[44mThe astonish TRICORN !\e[0m\n", 1);
	ft_putstr_fd("     \e[42mThe unbelivable JULIA !\e[0m\n", 1);
	ft_putstr_fd("Just type the fractal name and enjoy the show !\n", 1);
	ft_putstr_fd("	./fractal Mandelbrot \n\n", 1);
	ft_putstr_fd("\e[1;37m============== Instructions =============\e[0m\n", 1);
	ft_putstr_fd("Arrow Keys - move fractal around\n", 1);
	ft_putstr_fd("R and B - change Red and Blue color range \n", 1);
	ft_putstr_fd("Z and X - change Julia set values while running \n", 1);
	ft_putstr_fd("Esc - Leave the program IN A CLEAN WAY !!\n\n", 1);
	ft_putstr_fd("\e[1;37m=============== Julia set ===============\e[0m\n", 1);
	ft_putstr_fd("You can choose Julia constants in parameters \n", 1);
	ft_putstr_fd("/fractol Julia 0.1 -0.1 - Any value between -2.0 ~ 2.0\n", 1);
	ft_putstr_fd("Use Z and X to change Julia set values while running \n", 1);
	ft_putstr_fd("A - Reset Julia fractal to values 0.0 ~ 0.0 \n", 1);
	ft_putstr_fd("\e[1;37m=========================================\e[0m\n", 1);
	exit(200);
}

void	helpjulia(void)
{
	ft_putstr_fd("We need a value between 2.0 ~ -2.0 to run Julia\n", 1);
	ft_putstr_fd("Julia call example:", 1);
	ft_putstr_fd("\e[42m./fractol julia (number1) (number2)\e[0m\n", 1);
	exit(-1);
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
		return (-42);
	return (nb * neg);
}
