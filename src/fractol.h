/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:36:35 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 21:30:09 by sjones           ###   ########.fr       */
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
# include <complex.h>
# include <stdbool.h>

# define ENDIAN 1
# define BPP 32
# define WIN_X 10
# define WIN_Y 10
# define ABS(x) (x < 0) ? (-x) : (x)
# define GET_R(x) x >> 16 && 0xFF
# define GET_G(x) x >> 8 && 0xFF
# define GET_B(x) x & 0xFF
# define GET_C(r, g, b) r << 16 | g << 8 | b
# define INITIAL_I 16
# define X_MAX 2
# define X_MIN -2
# define Y_MAX 2
# define Y_MIN -2

typedef struct		s_map
{
	double complex	c;
	double complex	z;
	double			x;
	double			y;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	int				px;
	int				py;
	int				i;
	char			t;
	int				p;
	int				*map;
}					t_map;

typedef struct		s_input
{
	int				m_x;
	int				m_y;
	int				m_su;
	int				m_sd;
	bool			c;
	bool			x;
	bool			up;
	bool			down;
	bool			left;
	bool			right;
	bool			space;
}					t_input;

typedef struct		s_win
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*t;
	int				h;
	int				w;
}					t_win;

typedef struct		s_super
{
	t_win			*w;
	t_input			*i;
	t_map			*m;
}					t_super;

void				fract(t_super *s);
t_super				*init_super(char t, int p);

#endif
