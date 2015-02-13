/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/23 13:58:51 by exam              #+#    #+#             */
/*   Updated: 2014/11/27 14:41:16 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	if (!(*str))
		return (0);
	return (1 + ft_strlen(++str));
}

char	*ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = s2[i];
	return (s1);
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	dup = ft_strcpy(dup, str);
	return (dup);
}

char	*ft_strcat(char *grid, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (grid[i])
		i++;
	j = 0;
	while (str[j])
		grid[i++] = str[j++];
	grid[i++] = str[j++];
	return (grid);
}

char	*ft_realloc(char *grid, char *str, int i)
{
	char	*save;

	save = ft_strdup(grid);
	free(grid);
	if (!(grid = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	grid = ft_strcpy(grid, save);
	free(save);
	grid = ft_strcat(grid, str);
	return (grid);
}
