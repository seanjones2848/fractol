/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:36:35 by sjones            #+#    #+#             */
/*   Updated: 2017/11/30 16:17:39 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_keys_macros.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <pthread.h>

# define W s->w
# define M s->m
# define I s->i
# define IMG s->img
# define WIN_X 1000
# define WIN_Y 1000
# define ABS(x) (x < 0) ? (-x) : (x)
# define GET_R(x) x >> 16 && 0xFF
# define GET_G(x) x >> 8 && 0xFF
# define GET_B(x) x & 0xFF
# define GET_C(r, g, b) r << 16 | g << 8 | b
# define INITIAL_I 32
# define MAX_I 2048
# define X_MAX 2
# define X_MIN -2
# define Y_MAX 2
# define Y_MIN -2
# define ZIN .9
# define ZOUT 1.1
# define THREADS 8

enum
{
	in,
	out,
	up,
	down,
	left,
	right
}					direction;

typedef struct		s_thread
{
	double			cre;
	double			cim;
	double			nre;
	double			nim;
	double			ore;
	double			oim;
	double			sx;
	double			sy;
	double			zoom;
	int				px;
	int				py;
	int				i;
	char			t;
	int				p;
	int				c;
	int				ret;
	int				id;
	int				h;
	int				w;
	int				m_x;
	int				m_y;
	int				*data;
	int				size;
	pthread_mutex_t	lock;
}					t_thread;

typedef struct		s_map
{
	double			cre;
	double			cim;
	double			nre;
	double			nim;
	double			ore;
	double			oim;
	double			sx;
	double			sy;
	double			zoom;
	int				px;
	int				py;
	int				i;
	char			t;
	int				p;
	int				c;
	int				ret;
}					t_map;

typedef struct		s_input
{
	int				m_x;
	int				m_y;
	bool			m_l;
	bool			m_r;
	bool			m_su;
	bool			m_sd;
	bool			c;
	bool			x;
	bool			up;
	bool			down;
	bool			left;
	bool			right;
	bool			space;
	bool			draw;
	bool			esc;
}					t_input;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bpp;
	int				size;
	int				e;
}					t_img;

typedef struct		s_win
{
	void			*win;
	void			*mlx;
	char			*t;
	int				h;
	int				w;
}					t_win;

typedef struct		s_super
{
	t_win			*w;
	t_input			*i;
	t_map			*m;
	t_img			*img;
	pthread_mutex_t	lock;
}					t_super;

int					fract(t_super *s);
t_super				*init_super(char t, int p);
int					draw(t_super *s);
void				zoom(int dir, t_super *s);
void				move(int dir, t_super *s);
int					key_press(int key, t_super *s);
int					key_release(int key, t_super *s);
int					mouse_press(int key, int x, int y, t_super *s);
int					mouse_release(int key, int x, int y, t_super *s);
int					motion_hook(int x, int y, t_super *s);
int					expose_hook(t_super *s);
int					loop_hook(t_super *s);
int					colorize(t_thread *t);
void				shift_color(t_super *s);
void				revert(t_super *s);

#endif
