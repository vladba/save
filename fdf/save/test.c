/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:14:47 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/26 19:11:27 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "ft.h"

void	ligne(int xi, int yi, int xf, int yf, void *mlx, void *win)
{
	int		x;
	int		y;
	double	a;
	double	b;

	if (xi > xf)
		ligne(xf, yf, xi, yi, mlx, win);
	a = (double)(yf - yi) / (xf - xi);
	b = yi - a * xi;
	x = xi;
	while (x <= xf)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(mlx, win, x, y, 0xFF0000);
		x++;
	}
}

void		dessiner_ligne(void  *mlx, void *win, int xi, int yi, int xj, int yj)
{
	int		deltaX;
	int		deltaY;
	unsigned int	nb_pixels;
	float	deltaX_pixel;
	float	deltaY_pixel;
	float	pixel_x;
	float	pixel_y;
	unsigned int	i;

	deltaX = xj - xi;
	deltaY = yj - yi;
	nb_pixels = (unsigned int)fmax(fabs(deltaX), fabs(deltaY));
	deltaX_pixel = (float)deltaX / nb_pixels;
	deltaY_pixel = (float)deltaY / nb_pixels;
	i = 1;
	pixel_x = xi;
	pixel_y = yi;
	while (i++ < nb_pixels)
	{
		mlx_pixel_put(mlx, win, ceil(pixel_x), ceil(pixel_y), 0xFEFEFE);
		pixel_x = pixel_x + deltaX_pixel;
		pixel_y = pixel_y + deltaY_pixel;
	}
	mlx_pixel_put(mlx, win, xj, yj, 0xFEFEFE);
}

int		main()
{
	t_env e;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	t_point p1, p2;

	p1.abs = 300;
	p1.ord = 400;
	p2.abs = 200;
	p2.ord = 100;
	draw_line(&e, p1, p2, 0xFEFEFE);
	sleep(7);
}
