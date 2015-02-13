/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 03:40:56 by vbargues          #+#    #+#             */
/*   Updated: 2015/01/28 13:27:52 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>

void	adapt_pixel_in_image(t_env **win, int color, int x, int y)
{
	unsigned int	stock;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				value;

	value = y * (*win)->img.sl + x * ((*win)->img.bpp >> 3);
	if (y < 0 || x < 0 || y >= (*win)->height || x >= (*win)->width)
		return ;
	stock = mlx_get_color_value((*win)->mlx, color);
	red = ((stock & 0xFF0000) >> 16);
	green = ((stock & 0xFF00) >> 8);
	blue = (stock & 0xFF);
	((*win)->img.data)[value] = blue;
	((*win)->img.data)[value + 1] = green;
	((*win)->img.data)[value + 2] = red;
}
