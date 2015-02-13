/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:41:04 by vbargues          #+#    #+#             */
/*   Updated: 2014/11/28 14:38:45 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 1024
typedef struct	s_struct
{
	int			l;
	int			c;
	int			**tab;
}				t_struct;

typedef struct	s_point
{
	int			abs;
	int			ord;
}				t_point;

typedef struct	s_line
{
	t_point		pt1;
	t_point		pt2;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;


int				ft_verif(char *str, t_struct *map);
void			grid(t_struct map, t_env e);
void			draw_line(t_env *win, t_point pt1, t_point pt2, int color);
char			*ft_realloc(char *grid, char *str, int i);

#endif
