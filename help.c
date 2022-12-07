/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 06:20:06 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/07 06:41:36 by dvargas          ###   ########.fr       */
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