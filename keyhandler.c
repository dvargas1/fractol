/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:33:51 by dvargas           #+#    #+#             */
/*   Updated: 2022/12/08 07:29:05 by dvargas          ###   ########.fr       */
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
/*
int handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return 0;
}
*/