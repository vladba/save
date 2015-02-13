/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:14:47 by vbargues          #+#    #+#             */
/*   Updated: 2015/01/08 00:42:39 by vbargues         ###   ########.fr       */
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

void	ft_fill(int x, int y, int color, t_env e)
{
//	if (ce pixel est de couleur color)
//		return ;
	mlx_pixel_put(e.mlx, e.win, x, y, color);
	ft_fill(x, y + 1, color, e);
	ft_fill(x + 1, y, color, e);
	ft_fill(x - 1, y, color, e);
	ft_fill(x, y - 1, color, e);
}

void	draw_circle(int r, int x_centre, int y_centre, int color, t_env e)
{
	int x = 0;
	int y = r;
	int d = r - 1;
	
	while (y >= x)
	{
		mlx_pixel_put(e.mlx, e.win, x_centre + x, y_centre + y, color);
		mlx_pixel_put(e.mlx, e.win, x_centre + y, y_centre + x, color);
		mlx_pixel_put(e.mlx, e.win, x_centre - x, y_centre + y, color);
		mlx_pixel_put(e.mlx, e.win, x_centre - y, y_centre + x, color);
		mlx_pixel_put(e.mlx, e.win, x_centre + x, y_centre - y, color);
		mlx_pixel_put(e.mlx, e.win, x_centre + y, y_centre - x, color);
		mlx_pixel_put(e.mlx, e.win, x_centre - x, y_centre - y, color);
		mlx_pixel_put(e.mlx, e.win, x_centre - y, y_centre - x, color);
		if (d >= 2 * x)
		{
			d = d - 2 * x - 1;
			x++;
		}
		else if (d < 2 * (r - y))
		{
			d = d + 2 * y - 1;
			y--;
		}
		else
		{
			d = d + 2 * (y - x - 1);
			y--;
			x++;
		}
	}
//	ft_fill(x_centre, y_centre, color, e);
/*	Si d >= 2x alors 
	d <- d-2x-1
	x <- x+1
	Sinon Si d < 2(r-y) alors
	d <- d+2y-1
	y <- y-1     
	Sinon 
d <- d+2(y-x-1)
	y <- y-1
	x <- x+1
	Fin de tant que*/
}

int		main()
{
	t_env e;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "42");
	t_point p1, p2;

	p1.abs = 300;
	p1.ord = 400;
	p2.abs = 200;
	p2.ord = 100;
	draw_circle(300, 500, 500, 0xFEFEFE, e);
	sleep(7);
}
