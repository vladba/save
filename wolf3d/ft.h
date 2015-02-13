/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:41:04 by vbargues          #+#    #+#             */
/*   Updated: 2014/12/10 23:07:36 by vbargues         ###   ########.fr       */
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
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	double		angle;
	int			x;
	int			y;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_param
{
	t_struct	map;
	t_player	player;
	t_env		e;
	double		angle;
	int			P;
}				t_param;


t_struct		to_tab(char *str, t_struct map);
char			*ft_read(char *str);
void			grid(t_struct map, t_env e);
void			draw_line(t_env *win, t_point pt1, t_point pt2, int color);
char			*ft_realloc(char *grid, char *str, int i);

#endif
