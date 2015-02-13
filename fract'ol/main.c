/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargue-> <vbargue->@stude->t.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   c_re->te->: 2015/01/14 03:09:48 by vbargue->          #+#    #+#             */
/*   Update->: 2015/01/28 11:57:19 by vbargue->         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include </usr/X11/include/X11/X.h>

int		ft_vlad(t_env *e, double x, double y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

//	c_r = -0.216636;
//	c_i = -0.371316;
	c_r = -0.356449;
	c_i = 0.397325;
//	c_r = -0.707384;
//	c_i = 0.006016;
//	c_r = e->>mouse->x / e->>width * (e->>x_max - e->>x_min) + e->>x_min;
//	c_i = e->>mouse->y / e->>he->ght * (e->>y_max - e->>y_min) + e->>y_min;
	e->i = -1;
//	z_i = 2 * x * y + c_i;
//	z_r = x * x - y * y + c_r;
	z_i = x;
	z_r = y;
	while (++e->i < (int)e->it_max && z_i * z_i + z_r * z_r < 4/* + 0.5 * (e->>x_max - e->>x_min)*/)
	{
		tmp = z_r;
		z_r = tan((z_r * z_r) - (z_i * z_i)) + c_r;
//		z_r = 3 * (z_r * z_r * z_r) + z_r - 3 * (z_i * z_i * z_i) + c_r;
		z_i = 6 * tmp * z_i + z_i + c_i;
	}
	if (e->i == 0)
		return (0);
//	if (e->>i == e->>it_max)
//		re->urn (0);
	return (((int)(0 * (e->i / e->it_max)) << 16) + ((int)(255 * (e->i / e->it_max)) << 8) + (255 * (e->i / e->it_max)));
	if (e->it_max / e->i > e->it_max * 0.9)
		return (0);
	if (e->i * (e->x_max - e->x_min) < 15)
		return (0x000030);
	if (e->i * (e->x_max - e->x_min) < 30)
		return (0x000060);
	if (e->i * (e->x_max - e->x_min) < 45)
		return (0x004080);
	if (e->i * (e->x_max - e->x_min) < 75)
		return (0x0080A0);
	if (e->i * (e->x_max - e->x_min) < 90)
		return (0x00FFFF);
	if (e->i * (e->x_max - e->x_min) < 120)
		return (0x00FFA0);
	if (e->i * (e->x_max - e->x_min) < 150)
		return (0x008050);
	if (e->i * (e->x_max - e->x_min) < 180)
		return (0x408000);
	if (e->i * (e->x_max - e->x_min) < 210)
		return (0x908000);
	return (0xB08000);
}

int		ft_mandel(t_env *e, double x, double y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	c_i = y;
	c_r = x;
//	c_r = e->C_r;
//	c_i = e->C_i;
	z_i = 0;
	z_r = 0;
	if (e->C_mouse == 0)
	{
		z_r = e->mouse_x / e->width * (e->x_max - e->x_min) + e->x_min;
		z_i = e->mouse_y / e->height * (e->y_max - e->y_min) + e->y_min;
	}
	e->i = -1;
//	z_i = 2 * x * y + c_i;
//	z_r = x * x - y * y + c_r;
	while (++e->i < (int)e->it_max && z_i * z_i + z_r * z_r < 4/* + 0.5 * (e->>x_max - e->>x_min)*/)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp *z_i + c_i;
	}
	if (e->i == 0)
		return (0);
//	if (e->>i == e->>it_max)
//		re->urn (0);
	return (((int)(0 * (e->i / e->it_max)) << 16) + ((int)(255 * (e->i / e->it_max)) << 8) + (255 * (e->i / e->it_max)));
	if (e->it_max / e->i > e->it_max * 0.9)
		return (0);
	if (e->i * (e->x_max - e->x_min) < 15)
		return (0x000030);
	if (e->i * (e->x_max - e->x_min) < 30)
		return (0x000060);
	if (e->i * (e->x_max - e->x_min) < 45)
		return (0x004080);
	if (e->i * (e->x_max - e->x_min) < 75)
		return (0x0080A0);
	if (e->i * (e->x_max - e->x_min) < 90)
		return (0x00FFFF);
	if (e->i * (e->x_max - e->x_min) < 120)
		return (0x00FFA0);
	if (e->i * (e->x_max - e->x_min) < 150)
		return (0x008050);
	if (e->i * (e->x_max - e->x_min) < 180)
		return (0x408000);
	if (e->i * (e->x_max - e->x_min) < 210)
		return (0x908000);
	return (0xB08000);
}

int		ft_julia(t_env *e, double x, double y)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	c_r = e->C_r;
	c_i = e->C_i;
	if (e->C_mouse == 0)
	{
		c_r = e->mouse_x / e->width * (e->x_max - e->x_min) + e->x_min;
		c_i = e->mouse_y / e->height * (e->y_max - e->y_min) + e->y_min;
	}
	e->i = -1;
//	z_i = 2 * x * y + c_i;
//	z_r = x * x - y * y + c_r;
	z_i = y;
	z_r = x;
	while (++e->i < (int)e->it_max && z_i * z_i + z_r * z_r < 4)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp *z_i + c_i;
	}
	if (e->i == 0)
		return (0);
	return (((int)(0 * (e->i / e->it_max)) << 16) + ((int)(255 * (e->i / e->it_max)) << 8) + (255 * (e->i / e->it_max)));
	if (e->it_max / e->i > e->it_max * 0.9)
		return (0);
	if (e->i * (e->x_max - e->x_min) < 15)
		return (0x000030);
	if (e->i * (e->x_max - e->x_min) < 30)
		return (0x000060);
	if (e->i * (e->x_max - e->x_min) < 45)
		return (0x004080);
	if (e->i * (e->x_max - e->x_min) < 75)
		return (0x0080A0);
	if (e->i * (e->x_max - e->x_min) < 90)
		return (0x00FFFF);
	if (e->i * (e->x_max - e->x_min) < 120)
		return (0x00FFA0);
	if (e->i * (e->x_max - e->x_min) < 150)
		return (0x008050);
	if (e->i * (e->x_max - e->x_min) < 180)
		return (0x408000);
	if (e->i * (e->x_max - e->x_min) < 210)
		return (0x908000);
	return (0xB08000);
}

int		ft_draw(t_env *e)
{
	double	x;
	double	y;
	double	x2;
	double	y2;

	x = -1;
//	printf("%f %f\n", e->>mouse->x / e->>width * (e->>x_max - e->>x_min) + e->>x_min, e->>mouse->y / e->>he->ght * (e->>y_max - e->>y_min) + e->>y_min);
	while (++x < e->width)
	{
		y = -1;
		while (++y < e->height)
		{
			x2 = x / e->width * (e->x_max - e->x_min) + e->x_min;
			y2 = y / e->height * (e->y_max - e->y_min) + e->y_min;
			adapt_pixel_in_image(&e, (e->ptr_fonction)(e, x2, y2), x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int		loop_hook_one(t_env *e)
{
	if (e->down_pressed || e->up_pressed || e->left_pressed || e->right_pressed)
		ft_move(&(e));
	if (e->moins)
		(e)->it_max -= 1;
	if (e->plus)
		(e)->it_max += 1;
	if (e->exit)
		exit(0);
	ft_draw(e);
	return (0);
}

void	ft_one_win(t_env *e)
{

	mlx_expose_hook(e->win, ft_draw, e);
	mlx_hook(e->win, KeyPress, KeyPressMask, key_press, &(e));
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, key_release, &(e));
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_motion, &(e));
	mlx_mouse_hook(e->win, mouse_hook, &(e));
	mlx_loop_hook(e->mlx, loop_hook_one, e);
	mlx_loop(e->mlx);
}

int		loop_hook(t_win *win)
{
	if (win->e->exit)
	{
		mlx_destroy_window(win->e->mlx, win->e->win);
//		free (win->e);
		ft_one_win(win->ee);
	}
	if (win->ee->exit)
	{
		mlx_destroy_window(win->e->mlx, win->ee->win);
//		free (win->ee);
		ft_one_win(win->e);
	}
	if (win->e->down_pressed || win->e->up_pressed || win->e->left_pressed || win->e->right_pressed)
		ft_move(&(win->e));
	if (win->ee->down_pressed || win->ee->up_pressed || win->ee->left_pressed || win->ee->right_pressed)
		ft_move(&(win->ee));
	if (win->e->moins)
		(win->e)->it_max -= 1;
	if (win->e->plus)
		(win->e)->it_max += 1;
	if (win->ee->moins)
		(win->ee)->it_max -= 1;
	if (win->ee->plus)
		(win->ee)->it_max += 1;
	if (win->e->draw || win->e->plus || win->e->moins)
		ft_draw(win->e);
	if (win->ee->draw || win->ee->plus || win->ee->moins)
		ft_draw(win->ee);
	win->ee->draw = 0;
	win->e->draw = 0;
	return (0);
}

void	ft_init(t_env **e)
{
	(*e)->x_max = 1.4;
	(*e)->y_max = 1.6;
	(*e)->x_min = -1.8;
	(*e)->y_min = -1.6;
	(*e)->it_max = 30;
	(*e)->down_pressed = 0;
	(*e)->up_pressed = 0;
	(*e)->left_pressed = 0;
	(*e)->right_pressed = 0;
}

int		main()
{
	t_env	*e;
	t_env	*ee;
	t_win	win;

	e = malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->next = malloc(sizeof(t_env));
	e->next->mlx = e->mlx;
	e->width = 810;
	e->height = 720;
	e->next->width = 810;
	e->next->height = 720;
	ft_init(&e);
	ft_init(&(e->next));
	e->it_zoom = 0.1;
	e->next->it_zoom = 0.1;
	e->next->next = NULL;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "fract'ol");
	e->next->win = mlx_new_window(e->next->mlx, e->next->width, e->next->height, "fract'ol2");
	e->img.img = mlx_new_image(e->mlx, e->width, e->height);
	e->img.height = e->height;
	e->img.width = e->width;
	e->img.data = mlx_get_data_addr(e->img.img, &(e->img.bpp), &(e->img.sl), &(e->img.endian));
	e->next->img.img = mlx_new_image(e->next->mlx, e->next->width, e->next->height);
	e->next->img.height = e->height;
	e->next->img.width = e->width;
	e->next->img.data = mlx_get_data_addr(e->next->img.img, &(e->next->img.bpp), &(e->next->img.sl), &(e->next->img.endian));
//		if (strcmp(argv[1], "Mandelbrot") == 0)
		e->next->ptr_fonction = ft_julia;
		e->ptr_fonction = ft_mandel;
	ee = e->next;
	win.e = e;
	win.ee = ee;
	mlx_do_key_autorepeatoff(e->mlx);
	mlx_expose_hook(e->win, ft_draw, e);
	mlx_hook(e->win, KeyPress, KeyPressMask, key_press, &(e));
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, key_release, &(e));
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_motion, &(e));
	mlx_mouse_hook(e->win, mouse_hook, &(e));
	mlx_expose_hook(ee->win, ft_draw, ee);
	mlx_hook(ee->win, KeyPress, KeyPressMask, key_press, &(ee));
	mlx_hook(ee->win, KeyRelease, KeyReleaseMask, key_release, &(ee));
	mlx_hook(ee->win, MotionNotify, PointerMotionMask, mouse_motion, &(ee));
	mlx_mouse_hook(ee->win, mouse_hook, &(ee));
	mlx_loop_hook(e->mlx, loop_hook, &win);
	mlx_loop(e->mlx);
	return (0);
}
