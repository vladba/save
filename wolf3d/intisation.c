/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intisation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:17:57 by vbargues          #+#    #+#             */
/*   Updated: 2014/12/12 20:55:09 by vbargues         ###   ########.fr       */
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
