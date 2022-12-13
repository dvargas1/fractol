/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:28:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/13 17:31:59 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//Includes
# include <stdlib.h>
# include "mlx/mlx.h"
//# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
//# include <X11/X.h>
//# include <X11/keysym.h>

//KeyDefines
# define CLOSE_BTN 17
# define ESC_KEY 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_R 15
# define KEY_B 11
# define KEY_Z 6
# define KEY_X 7
# define KEY_A 0

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
	char			*fname;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	unsigned int	data;
	double			minr;
	double			mini;
	double			maxr;
	double			maxi;
	double			juliar;
	double			juliai;
	double			datacr;
	double			dataci;
	unsigned int	colorred;
	unsigned int	colorblue;
}				t_data;

//Render
void	ft_render(t_data *data);

//Initialization
void	create_img(t_data *data);
void	ft_init(t_data *data, int argc, char **argv);

//FractalSets
double	juliaset(t_data *data);
double	mandelbrotset(t_data *data);
double	tricornset(t_data *data);

// Utils
double	ft_atof(char *str, double nb, int neg, double div);
void	help(void);
void	helpjulia(void);
int		endgame(t_data *data);

//Event Handlers
int		handler_mouse(int keysym, int x, int y, t_data *data);
int		handler_keypress(int keysym, t_data *data);

#endif
