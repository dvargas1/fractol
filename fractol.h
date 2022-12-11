/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:28:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/11 09:13:14 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACT_H
# define LIB_FRACT_H

//Includes
# include <stdlib.h>
//# include "minilibx_opengl/mlx.h"
#include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

//KeyDefines
# define CLOSE_BTN 17
// # define ESC_KEY 53
 # define ESC_KEY 53
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3

// Screen size and mx iterations
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATION 200

//Structs

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
	double datacr;
	double dataci;
	unsigned int colorR;
	unsigned int colorB;
}				t_data;

//Colors and Render
void ft_render(t_data *data);

//Initialization
void create_img(t_data *data);
void ft_preparejulia(t_data *data,int argc, char **argv);
void ft_init(t_data *data,int argc, char **argv);
void ft_checkname(t_data *data,char *name);

//FractalSets
double	juliaset(t_data *data);
double	mandelbrotset(t_data *data);
double	tricornset(t_data *data);
void ft_preparejulia(t_data *data,int argc, char **argv);

//KeyHandlers
int handle_keypress(int keysym, t_data *data);

// Utils
double	ft_atof(char *str, double nb, int neg, double div);
void help();
void helpjulia(t_data *data);
int delete_img(t_data *data);
int	endgame(t_data *data);


//Event Handlers
double	ft_translate(double start, double end, double trans);
void ft_colorchange(t_data *data, int i, int flag);
int mouse_handler(int keysym, int x, int y, t_data *data);
int handler_keypress(int keysym, t_data *data);


#endif
