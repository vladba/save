/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalomme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 18:27:03 by lsalomme          #+#    #+#             */
/*   Updated: 2014/11/27 19:51:27 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft.h"
#include <stdlib.h>

void	draw_hv(t_env *win, t_line line, int color)
{
	if (line.dy == 0)
		while (line.pt1.abs < line.pt2.abs)
			mlx_pixel_put(win->mlx, win->win,
			(line.pt1.abs)++, line.pt1.ord, color);
	if (line.dx == 0)
	{
		while (line.pt1.ord < line.pt2.ord)
			mlx_pixel_put(win->mlx, win->win, line.pt1.abs,
			(line.pt1.ord)++, color);
		while (line.pt2.ord < line.pt1.ord)
			mlx_pixel_put(win->mlx, win->win, line.pt2.abs,
			(line.pt2.ord)++, color);
	}
}

void	draw_o1(t_env *win, t_line line, int color)
{
	int e;

	e = line.dx;
	(line.dx) *= 2;
	(line.dy) *= 2;
	while (1)
	{
		mlx_pixel_put(win->mlx, win->win, line.pt1.abs, line.pt1.ord, color);
		if (++(line.pt1.abs) == line.pt2.abs)
			break ;
		if ((e = e - line.dy) < 0)
		{
			(line.pt1.ord)++;
			e += line.dx;
		}
	}
}

void	draw_o2(t_env *win, t_line line, int color)
{
	int e;

	e = line.dy;
	(line.dy) *= 2;
	(line.dx) *= 2;
	while (1)
	{
		mlx_pixel_put(win->mlx, win->win, line.pt1.abs, line.pt1.ord, color);
		if (++(line.pt1.ord) == line.pt2.ord)
			break ;
		if ((e = e - line.dx) < 0)
		{
			(line.pt1.abs)++;
			e += line.dy;
		}
	}
}

void	draw_o8(t_env *win, t_line line, int color)
{
	int e;

	e = line.dx;
	(line.dx) *= 2;
	(line.dy) *= 2;
	while (1)
	{
		mlx_pixel_put(win->mlx, win->win, line.pt1.abs, line.pt1.ord, color);
		if (++(line.pt1.abs) == line.pt2.abs)
			break ;
		if ((e += line.dy) < 0)
		{
			(line.pt1.ord)--;
			e += line.dx;
		}
	}
}

void	draw_o7(t_env *win, t_line line, int color)
{
	int e;

	e = line.dy;
	(line.dy) *= 2;
	(line.dx) *= 2;
	while (1)
	{
		mlx_pixel_put(win->mlx, win->win, line.pt1.abs, line.pt1.ord, color);
		if (--(line.pt1.ord) == line.pt2.ord)
			break ;
		if ((e += line.dx) > 0)
		{
			(line.pt1.abs)++;
			e += line.dy;
		}
	}
}

void	draw_line(t_env *win, t_point pt1, t_point pt2, int color)
{
	t_line line;

	line.pt1 = pt1;
	line.pt2 = pt2;
	if (pt2.abs < pt1.abs)
	{
		line.pt1 = pt2;
		line.pt2 = pt1;
	}
	line.dx = line.pt2.abs - line.pt1.abs;
	line.dy = line.pt2.ord - line.pt1.ord;
	if (line.dx > 0 && line.dy > 0 && line.dx >= line.dy)
		draw_o1(win, line, color);
	else if (line.dx > 0 && line.dy > 0 && line.dx < line.dy)
		draw_o2(win, line, color);
	else if (line.dx > 0 && line.dy < 0 && line.dx >= -(line.dy))
		draw_o8(win, line, color);
	else if (line.dx > 0 && line.dy < 0 && line.dx < -(line.dy))
		draw_o7(win, line, color);
	else if (line.dx == 0 || line.dy == 0)
		draw_hv(win, line, color);
}
