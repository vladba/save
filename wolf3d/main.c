/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:38:20 by vbargues          #+#    #+#             */
/*   Updated: 2015/01/28 01:43:05 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

t_point	first_y(t_struct map, t_player player, double angle)
{
	t_point	p;
	int		x;
	int		y;

	x = 64;
	if (fabs(angle) < M_PI / 2)
		p.x = (int)(player.x / x) * x + x;
	else
		p.x = (int)(player.x / x) * x - 1;
	p.y = player.y + (player.x - p.x) * tan(angle);
	if (fabs(angle) > M_PI / 2)
		x = -x;
	y = x * tan(angle);
	if (p.y < 0)
		p.y = 0;
	if (p.y / 64 >= map.l)
		p.y = map.l * 64 - 1;
	//printf("plop\n");
	while (map.tab[p.y / 64][p.x / 64] < 10)
	{
		p.x += x;
		p.y += y;
		printf("%d   %d\n", p.x/64, p.y/64);
		if (p.y < 0)
			p.y = 0;
		if (p.y / 64 >= map.l)
			p.y = map.l * 64 - 1;
	}
	return (p);
}

t_point	first_x(t_struct map, t_player player, double angle)
{
	t_point	p;
	int		x;
	int		y;

	y = 64;
	if (angle > 0)
		p.y = (int)(player.y/y) * y - 1;
	else
		p.y = (int)(player.y/y) * y + y;
	p.x = player.x + (player.y - p.y) / tan(angle);
	if (angle > 0)
		y = -y;
	x = y / tan(angle);
	if (p.x < 0)
		p.x = 0;
	if (p.x >= map.c * 64)
		p.x = map.c *64 - 1;
	while (map.tab[p.y / 64][p.x / 64] < 10)
	{
		p.x += x;
		p.y += y;
	}
//	printf("%d   %d\n", p.x/64, p.y/64);
	return (p);
}

void	ft_colonne(int P, t_env e, int wall)
{
	int		i;

	i = 0;
	while (i < 100 - wall / 2)
		mlx_pixel_put(e.mlx, e.win, P, i++, 0xFF14C1);
	while (i <= 100 + wall / 2)
		mlx_pixel_put(e.mlx, e.win, P, i++, 0x7FFF00);
	while (i < 200)
		mlx_pixel_put(e.mlx, e.win, P, i++, 0x2BFAFA);
}

int		ft_draw(t_param *param)
{
	t_point	p1;
	t_point	p2;
	double	P;
	double	angle;
	int		wall;
	int debug;

	angle = param->player.angle + param->angle;
	if (angle > M_PI)
		angle -= 2 * M_PI;
	if (angle < - M_PI)
		angle += 2 * M_PI;
	p1 = first_x(param->map, param->player, angle);
	p2 = first_y(param->map, param->player, angle);
	//printf("%d  %d\n", p2.x / 64, p2.y / 64);
	P = sqrt(pow(abs(p1.x - param->player.x), 2) + pow(abs(param->player.y - p1.y), 2));
	debug = P;
	if (sqrt(pow(abs(p2.x - param->player.x), 2) + pow(abs(param->player.y - p2.y), 2)) < P)
		P = sqrt(pow(abs(p2.x - param->player.x), 2) + pow(abs(param->player.y - p2.y), 2));
//		printf("plop\n");}
//	if (!(debug != P))
//		printf("%d  %d\n", p2.x / 64, p2.y / 64);
//	else
//		printf("%d  %d\n", p1.x / 64, p1.y / 64);
//	P = 124;
//	if (P == 0)
//		P++;
	//printf("%d\n", P);
//	printf("%f\n", angle);
	if (param->angle > 0)
		P *= cos(- param->angle);
	else
		P *= cos(param->angle);
	//printf("%d\n", P);
	wall = 64 * 277 / P;
//	printf("%d\n", wall);
	ft_colonne(param->P--, param->e, wall);
	param->angle += M_PI / 960;
//	usleep(3000);
	if (param->P >= 0)
		ft_draw(param);
}

int		key_hook(int keycode, t_param *param)
{
	if (keycode == 65363)
		param->player.angle -= 0.1;
	if (keycode == 65361)
		param->player.angle += 0.1;
	if (keycode == 65307)
		exit(1);
	return (0);
}

int		ft_loop(t_param *param)
{
	printf("plop\n");
	ft_draw(param);
}

int		main()
{
	char		*str;
	t_param		param;

	param.player.x = 352;
	param.player.y = 300;
	param.map.c = 11;
	param.map.l = 10;
	param.player.angle = M_PI / 2;
	param.e.mlx = mlx_init();
	param.e.win = mlx_new_window(param.e.mlx, 320, 200, "42");
	param.angle = - M_PI / 6;
	param.P = 319;
	str = ft_read("map");
	param.map = to_tab(str, param.map);
	mlx_expose_hook(param.e.win, ft_draw, &param);
	mlx_key_hook(param.e.win, key_hook, &param);
	mlx_loop_hook(param.e.win, ft_loop, &param);
	mlx_loop(param.e.mlx);
	return (0);
}
