/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 06:20:06 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/09 21:27:31 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void help(t_data *data)
{
    ft_putstr_fd("Welcome to the incredible world of fractals !\n", 1);
    ft_putstr_fd("Today we have 3 types of fractals to show you\n", 1);
    ft_putstr_fd("The incredible MANDELBROT !\n", 1);
    ft_putstr_fd("The astonish TRICORN !\n", 1);
    ft_putstr_fd("The unbelivable JULIA !\n", 1);
    ft_putstr_fd("Just type the fractal name and enjoy the show !\n", 1);
    ft_putstr_fd("Remember, if you choose JULIA set, the next two arguments will be the consant size, please choose any number beetween 2.0 and -2.0 please\n", 1);
    endgame(data);
}

void helpjulia(t_data *data)
{
    ft_putstr_fd("Sorry we need a value between 2.0 ~ -2.0 to run Juliaset properly\n",1);
    endgame(data);

}

int	endgame(t_data *data)
{
    if(data->img)
        mlx_destroy_image(data->mlx_ptr, data->img);
    if(data->mlx_ptr && data->win_ptr)
    {
	    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        free(data->mlx_ptr);
    }
    ft_putstr_fd("Thats all folks\n",1);
	exit(0);
}
