/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:17:50 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/26 15:06:12 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_pushfront(t_list **t_start, int fd)
{
	t_list	*tmp;
	t_list	*new;

	if (!(*t_start))
	{
		if (!(new = (t_list *)malloc(sizeof(t_list *))))
			return (NULL);
		if (!(new->grid = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		*(new->grid) = 0;
		tmp = *t_start;
		new->f_d = fd;
		new->next = tmp;
		*t_start = new;
	}
	if ((*t_start)->f_d == fd)
		return (*t_start);
	return (ft_pushfront(&((*t_start)->next), fd));
}

char	*ft_realloc(char *grid, char *str)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup(grid);
	len = ft_strlen(grid) + ft_strlen(str);
	if (grid)
		ft_strdel(&grid);
	if (!(grid = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (!(tmp))
		return (NULL);
	grid = ft_strcpy(grid, tmp);
	grid = ft_strncat(grid, str, len + 1);
//	ft_strdel(&tmp);
	return (grid);
}

char	*ft_read(int fd, char *grid)
{
	int		ret;
	char	*str;

	if (ft_strchr(grid, '\n'))
		if (*(ft_strchr(grid, '\n') + 1))
			return (grid);
	if (!(str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[ret] = '\0';
		grid = ft_realloc(grid, str);
		if (!(grid) || ret < 0)
			return (NULL);
		if (ft_strchr(grid, '\n'))
			if (*(ft_strchr(grid, '\n') + 1))
				break;
	}
	free(str);
	return (grid);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*t_start = NULL;
	t_list			*t_grid;
	int				i;
	char			*tmp;

	i = 0;
	t_grid = ft_pushfront(&t_start, fd);
	if (!(t_grid) || (fd < 3 && fd != 0))
		return (-1);
	tmp = ft_strdup(t_grid->grid);
	tmp = ft_read(fd, tmp);
	if (!(tmp))
		return (-1);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	(*line)[i] = 0;
	*line = ft_strncpy(*line, tmp, i);
	if (tmp[0] == 0)
	{
		t_grid->grid = ft_strdup(tmp + i);
		free(tmp);
		return (0);
	}
	t_grid->grid = ft_strdup(tmp + i + 1);
	free(tmp);
	return (1);
}
