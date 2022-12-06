/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:28:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/06 08:54:44 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

//Includes
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

// Screen size and mx iterations
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900
# define MAX_ITERATION 200

//Colors
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define GOLD_PIXEL 0xFFD700


//Structs

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
	char *fname;
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
	unsigned int data;
	double minR;
	double minI;
	double maxR;
	double maxI;
	double jr;
	double ji;
}				t_data;

//Colors and Render
void ft_render(t_data *data);

//FractalSets
double	juliaset(t_data *data, double zr, double zi);
double	mandelbrotset(double cr, double ci);
double	tricornset(double cr, double ci);

//KeyHandlers
int handle_keypress(int keysym, t_data *data);

// Utils
double	ft_atof(char *str);


#endif
