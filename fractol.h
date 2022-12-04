/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:28:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/02 09:19:19 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

//Includes
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

// Screen size and mx iterations
# define WINDOW_WIDTH 1000.0
# define WINDOW_HEIGHT 1000.0
# define MAX_ITERATION 60

// Where Fractal starts.
# define R_BEG -2.5
# define R_END 1.5
# define I_BEG -2.0
# define I_END 2.0
//Colors
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define GOLD_PIXEL 0xFFD700
//Structs

typedef struct s_img
{
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
	unsigned int data;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;


typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
}				t_data;

typedef struct s_valor
{
	double x;
	double y;
}	t_valor;

typedef struct s_fractol
{
	double zi;
	double zr;
	double minR;
	double minI;
	double maxR;
	double maxI;
	char *buf;
}	t_fractol;


#endif
