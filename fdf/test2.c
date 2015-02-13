/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:14:47 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/26 16:46:41 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_env
{
	void *mlx;
	void *win;
}				t_env;

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
		mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
		x++;
	}
}

int		mouse_hook(int x, int y, t_env *e)
{
	int i = -1;
	int j;

	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mlx_pixel_put(e->mlx, e->win, x - 1 + i, y - 1 + j, 0xFFFF00);
	}
	return (0);
}

int		key_hook(int keycode, void *e)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main()
{
	t_env e;
	
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "42");

	mlx_hook(e.win, 1, (1L<<8), mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
