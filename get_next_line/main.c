/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kefleury <kefleury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:25:55 by kefleury          #+#    #+#             */
/*   Updated: 2015/01/28 05:32:11 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
//	else
//		fd = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
//		ft_putnbr(ret);
//		ft_putstr(" | ");
		ft_putstr(line);
		if (ret)
			ft_putchar('\n');
//		if (line)
			ft_memdel((void **)&line);
		get_next_line(0, &line);
		ft_putstr(line);
		if (ret)
			ft_putchar('\n');
		ft_memdel((void **)&line);
	}
//	if (line[0] != '\0' && ret == 0)
//	{
//		ft_putnbr(ret);
//		ft_putstr(" | ");
//		ft_putstr(line);
//		ft_putchar('\n');
//	}

/*		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');

		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');

		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');

		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');

		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');

		ret = get_next_line(fd, &line);
		ft_putnbr(ret);
		ft_putstr(" | ");
		ft_putstr(line);
		ft_putchar('\n');*/
	return (0);
}
