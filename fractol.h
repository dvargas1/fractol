/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:28:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/08 08:05:32 by dvargas          ###   ########.fr       */
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

//KeyDefines
# define CLOSE_BTN 17
# define ESC_KEY 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3

// Screen size and mx iterations
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900
# define MAX_ITERATION 100

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
	double juliar;
	double juliai;
	int color;
}				t_data;

//Colors and Render
void ft_render(t_data *data);

//Initialization
void create_img(t_data *data);
void ft_preparejulia(t_data *data,int argc, char **argv);
void ft_init(t_data *data,int argc, char **argv);
void ft_checkname(t_data *data,char *name);

//FractalSets
double	juliaset(t_data *data, double zr, double zi);
double	mandelbrotset(double cr, double ci);
double	tricornset(double cr, double ci);
void ft_preparejulia(t_data *data,int argc, char **argv);

//KeyHandlers
int handle_keypress(int keysym, t_data *data);

// Utils
double	ft_atof(char *str);
void help();
void helpjulia(t_data *data);
int delete_img(t_data *data);
int	endgame(t_data *data);


#endif
