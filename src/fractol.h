/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:36:35 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 14:42:14 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx_keys_macros.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <complex.h>

# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_map
{
	int				p;
}					t_map;

typedef struct		s_keys
{
	int				m_x;
	int				m_y;
	int				c;
}					t_keys;

typedef struct		s_win
{
	int				win;
	int				mlx;
	int				h;
	int				w;
	char			*t;
}					t_win;

typedef struct		s_super
{
	t_win			*w;
	t_keys			*k;
	t_map			*m;
}					t_super;


int					julia(double x, double y, double complex deg);
void				mandelbrot(int p);

#endif
