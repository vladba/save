/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbargues <vbargues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 03:45:41 by vbargues          #+#    #+#             */
/*   Updated: 2015/01/29 15:44:21 by vbargues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_img
{
	void		*img;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
}				t_img;

typedef struct	s_env
{
	int			j;
	int			(*ptr_fonction)(struct s_env *, double, double);
	void		*mlx;
	void		*win;
	double		width;
	double		height;
	t_img		img;
	double		i;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			down_pressed;
	int			up_pressed;
	int			left_pressed;
	int			right_pressed;
	double		mouse_x;
	double		mouse_y;
	double		it_max;
	double		it_zoom;
	double		C_r;
	double		C_i;
	int			C_mouse;
	int			draw;
	struct s_env	*next;
	int			exit;
	int			plus;
	int			moins;
}				t_env;

typedef struct	s_win
{
	t_env	*e;
	t_env	*ee;
}				t_win;

void	adapt_pixel_in_image(t_env **win, int color, int x, int y);
int		key_press(int keycode, t_env **win);
int		key_release(int keycode, t_env **win);
void	ft_move(t_env **e);
int		mouse_hook(int button, int x, int y, t_env **e);
int		mouse_motion(int x, int y, t_env **e);
void	ft_init(t_env **e);
int		ft_draw(t_env *e);

#endif
