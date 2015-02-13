/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:30:31 by vbargues          #+#    #+#             */
/*   Updated: 2014/12/04 19:40:17 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ligne(int xi, int yi, int xf, int yf, t_env *e)
{
	int		x;
	int		y;
	double	a;
	double	b;

	if (xi > xf)
		ligne(xf, yf, xi, yi, e);
	a = (double)(yf - yi) / (xf - xi);
	b = yi - a * xi;
	x = xi;
	while (x <= xf)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(e->mlx, e->win, x, y, 0xFEFEFE);
		x++;
	}
}

int		pixel_x(int i, int j, int l, int h)
{
	return (50 + 15 * j + 15 * (l - i - 1) + h / 10);
}

int		pixel_y(int i, int j, int c, int h)
{
	return (25 * i + 25 * j + 10 * (c - j - 1) - 2 * h - 100);
}

int		ft_color(t_struct map, int i, int j)
{
	int		color;
	int		t;

	t = map.tab[i][j];
	color = 0xFFFFFF;
	while (t--)
	{
		color -= 0x000050;
		if ((map.tab[i][j] - t) % 4 == 0)
		{
			color -= 0x005000;
			color += 0x0000F0;
		}
		if (((map.tab[i][j] - t) % 12 == 0))
		{
			color -= 0x500000;
			color += 0x00F000;
		}
	}
	return color;
}

void	ft_draw(int i, t_env e, int color, t_struct map)
{
	int		j;
	t_point	pt1;
	t_point	pt2;

	j = -1;
	while (++j < map.c)
	{
		pt1.abs = pixel_x(i, j, map.l, map.tab[i][j]);
		pt1.ord = pixel_y(i, j, map.c, map.tab[i][j]);
		if (j + 1 < map.c)
		{
			color = (map.tab[i][j + 1] > map.tab[i][j] ? ft_color(map, i, j + 1) : ft_color(map, i, j));
			pt2.abs = pixel_x(i, j + 1, map.l, map.tab[i][j + 1]);
			pt2.ord = pixel_y(i, j + 1, map.c, map.tab[i][j + 1]);
			draw_line (&e, pt1, pt2, color);
		}
		if (i + 1 < map.l)
		{
			color = (map.tab[i + 1][j] > map.tab[i][j] ? ft_color(map, i + 1, j) : ft_color(map, i, j));
			pt2.abs = pixel_x(i + 1, j, map.l, map.tab[i + 1][j]);
			pt2.ord = pixel_y(i + 1, j, map.c, map.tab[i + 1][j]);
			draw_line (&e, pt1, pt2, color);
		}
	}
}

void	grid(t_struct map, t_env e)
{
	int		i;
	int		j;
	int color = 0xFEFEFE;

	i = -1;
	while (++i < map.l)
		ft_draw (i, e, color, map);
}
