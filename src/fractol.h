/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:36:35 by sjones            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/10 14:42:14 by rlevine          ###   ########.fr       */
=======
/*   Updated: 2017/11/09 20:50:04 by sjones           ###   ########.fr       */
>>>>>>> ee9fa5d0ecc41f3ba801705ae301ce543260272f
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
<<<<<<< HEAD
# include <math.h>
# include <complex.h>
=======
# include <stdbool.h>
>>>>>>> ee9fa5d0ecc41f3ba801705ae301ce543260272f

# define WIN_X 1000
# define WIN_Y 1000
# define GET_R(x) x >> 16 && 0xFF
# define GET_G(x) x >> 8 && 0xFF
# define GET_B(x) x & 0xFF
# define GET_C(r, g, b) r << 16 | g << 8 | b

typedef struct		s_map
{
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


int					julia(double x, double y, double complex deg);
void				mandelbrot(int p);

#endif
