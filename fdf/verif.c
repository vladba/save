/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:02:40 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/27 20:13:26 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_verif(char *str, t_struct *map)
{
	int		i;
	int		j;
	int		col;

	map->l = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '\n'))
			return (0);
		if (str[i] == '\n')
		{
			if (map->l != 0 && j != map->c)
				return (0);
			i++;
			map->c = j;
			map->l++;
			j = 0;
		}
	}
	printf ("plop\n");
	return (1);
}
