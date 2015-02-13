/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intisation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:17:57 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/28 18:31:46 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_struct		to_tab(char *str, t_struct map)
{
	int			i;
	int			j;

	map.tab = (int **)malloc(sizeof(int *) * map.l);
	i = -1;
	while (++i < map.l)
	{
		j = -1;
		map.tab[i] = malloc(sizeof(int) * map.c);
		while (++j < map.c)
		{
			map.tab[i][j] = atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
			while (*str == ' ')
				str++;
		}
		str++;
	}
	return (map);
}

int		key_hook(int keycode, void *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

char	*ft_read(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i += ret;
		buf[ret] = '\0';
		str = ft_realloc(str, buf, i);
	}
	return (str);
}

int main(int argc, char **argv)
{
	char *str;
	t_struct map;
	t_env e;
	int i, j;

	str = ft_read(argv[1]);
	if (!(ft_verif(str, &map)))
		return (0);
	map = to_tab(str, map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 85 + 15 * (map.c + map.l), 25 * (map.l + map.c) - 80, "42");
	grid(map, e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
