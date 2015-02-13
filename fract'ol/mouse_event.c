/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 08:21:44 by vbargues          #+#    #+#             */
/*   Updated: 2015/01/29 15:23:57 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include </usr/X11/include/X11/X.h>
//#include "libft.h"

int		ft_zoom(t_env **e, int i)
{
	double	zoom;
	double	size_x;
	double	size_y;
	double	x;
	double	y;

	zoom = 0.99;
	(i) ? zoom = 1.01 : 1;
	size_x = ((*e)->x_max - (*e)->x_min) * zoom;
	size_y = ((*e)->y_max - (*e)->y_min) * zoom;
	x = (*e)->mouse_x / (*e)->width * ((*e)->x_max - (*e)->x_min) + (*e)->x_min;
	y = (*e)->mouse_y / (*e)->height * ((*e)->y_max - (*e)->y_min) + (*e)->y_min;
	(*e)->x_min = x - size_x / 2;
	(*e)->y_min = y - size_y / 2;
	(*e)->x_max = x + size_x / 2;
	(*e)->y_max = y + size_y / 2;
	size_x = (*e)->mouse_x / (*e)->width * ((*e)->x_max - (*e)->x_min) + (*e)->x_min;
	size_y = (*e)->mouse_y / (*e)->height * ((*e)->y_max - (*e)->y_min) + (*e)->y_min;
	(*e)->x_min += x - size_x;
	(*e)->x_max += x - size_x;
	(*e)->y_min += y - size_y;
	(*e)->y_max += y - size_y;
//	printf("%f %f\n", x, y);
//	ft_draw(*e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env **e)
{
	(*e)->mouse_x = x;
	(*e)->mouse_y = y;
	if (button == 4)
	{
		if ((*e)->it_max > 6)
			(*e)->it_max -= (*e)->it_zoom;
		ft_zoom(e, 1);
	}
	else if (button == 5)
	{
		(*e)->it_max += (*e)->it_zoom;
		ft_zoom(e, 0);
	}
	(*e)->draw = 1;
	return (0);
}

int		mouse_motion(int x, int y, t_env **e)
{
	(*e)->mouse_x = x;
	(*e)->mouse_y = y;
	(*e)->draw = 1;
//	ft_draw(*e);
	return (0);
}
