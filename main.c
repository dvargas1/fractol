/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:43:38 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/06 09:04:23 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
	}
	printf("Keypress: %d\n", keysym);
	return 0;
}

void ft_init(t_data *data, char **argv)
{
	data->fname = argv[1];
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->minR = -2.0;
	data->maxR = 1.0;
	data->minI = 2.0;
	data->maxI = -1.5;
	if(ft_strcmp(data->fname,"julia") == 0)
	{
		data->minR = -2.0;
		data->maxR = 2.0;
		data->minI = 2.0;
		data->maxI = -2.0;
		if(argc == 4)
		data->jr = ft_atof(argv[2]);
		data->ji = ft_atof(argv[3]);
	}
}

void create_img(t_data *data)
{
	if((data->mlx_ptr = mlx_init()) == NULL)
		return;
	//chamar funcao de erro
	if((data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol")) == NULL)
	{
		free(data->win_ptr);
		//chamar funcao de erro
	}
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
}

int main(int argc, char **argv)
{
	t_data data;

	if(argc < 2)
		return 1;
	ft_init(&data, argv);
	create_img(&data);
	ft_render(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress,&data);
//	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,&data);


	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

//Ver questao da inicializacao.
//construir as mensagens de ajuda e erro
//lidar com os hooks pedidos no mandatorio
//organizar melhor os codigos 
