/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:23:14 by lsalomme          #+#    #+#             */
/*   Updated: 2015/01/29 15:45:31 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include </usr/X11/include/X11/X.h>
//#include "libft.h"

int		key_press(int keycode, t_env **win)
{
	printf("%d\n", keycode);
	if (keycode == 65293)
	{
		if ((*win)->C_mouse == 0)
		{
			(*win)->C_mouse = 1;
			(*win)->C_r = (*win)->mouse_x / (*win)->width * ((*win)->x_max - (*win)->x_min) + (*win)->x_min;
			(*win)->C_i = (*win)->mouse_y / (*win)->height * ((*win)->y_max - (*win)->y_min) + (*win)->y_min;
		}
		else
			(*win)->C_mouse = 0;
	}
	if (keycode == 65451)
		(*win)->plus = 1;
	if (keycode == 65453)
		(*win)->moins = 1;
	if (keycode == 65307)
		(*win)->exit = 1;
	if (keycode == 65361)
		(*win)->left_pressed = 1;
	if (keycode == 65362)
		(*win)->up_pressed = 1;
	if (keycode == 65363)
		(*win)->right_pressed = 1;
	if (keycode == 65364)
		(*win)->down_pressed = 1;
	if (keycode == 32)
		ft_init(win);
	return (0);
}

int		key_release(int keycode, t_env **win)
{
	if (keycode == 65451)
		(*win)->plus = 0;
	if (keycode == 65453)
		(*win)->moins = 0;
	if (keycode == 65361)
		(*win)->left_pressed = 0;
	if (keycode == 65362)
		(*win)->up_pressed = 0;
	if (keycode == 65363)
		(*win)->right_pressed = 0;
	if (keycode == 65364)
		(*win)->down_pressed = 0;
	return (0);
}


void	ft_move(t_env **e)
{
	double	change;

	if ((*e)->left_pressed || (*e)->right_pressed)
	{
		change = ((*e)->x_max - (*e)->x_min) / 20;
		if ((*e)->left_pressed && ((*e)->x_max += change))
			(*e)->x_min += change;
		if ((*e)->right_pressed && ((*e)->x_max -= change))
			(*e)->x_min -= change;
	}
	if ((*e)->up_pressed || (*e)->down_pressed)
	{
		change = ((*e)->y_max - (*e)->y_min) / 20;
		if ((*e)->up_pressed && ((*e)->y_max += change))
			(*e)->y_min += change;
		if ((*e)->down_pressed && ((*e)->y_max -= change))
			(*e)->y_min -= change;
	}
	ft_draw(*e);
}
