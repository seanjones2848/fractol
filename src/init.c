/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:36 by sjones            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/09 13:45:16 by rlevine          ###   ########.fr       */
=======
/*   Updated: 2017/11/09 20:47:03 by sjones           ###   ########.fr       */
>>>>>>> ee9fa5d0ecc41f3ba801705ae301ce543260272f
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_win	*init_win(void)
{
	t_win	*w;

	if(!(w = (t_win*)malloc(sizeof(t_win))))
	{
		write(1, "malloc failed on t_win\n", 23);
		return NULL;
	}
	w->t = "Fract'ol";
	w->w = WIN_X;
	w->h = WIN_Y;
	w->mlx = mlx_init();
<<<<<<< HEAD
	w->win = mlx_new_window(w->mlx, w->w, w->h, win->t);
=======
	w->win = mlx_new_window(w->mlx, w->w, w->h, w->t);
	return (w);
}

static t_input	*init_input(void)
{
	t_input	*i;

	if (!(i = (t_input)malloc(sizeof(t_input))))
	{
		write(1, "malloc failed on t_input\n", 25);
		return NULL;
	}
	ft_bzero(i, sizeof(t_input));
	return (i);
}

static t_map	*init_map(char t, int p)
{
	t_map	*m;

	if (!(m = (t_map)malloc(sizeof(t_map))))
	{
		write(1, "malloc failed on t_map\n", 23);
		return NULL;
	}
	m->t = t;
	m->p = p;
	return (m);
}

t_super			*init_super(char t, int p)
{
	t_super	*s;

	if (!(s = (t_super*)malloc(sizeof(t_super))))
	{
		write(1, "malloc failed on t_super\n", 25);
		return NULL;
	}
	s->w = init_win();
	s->i = init_keys();
	s->m = init_map(t, p);
>>>>>>> ee9fa5d0ecc41f3ba801705ae301ce543260272f
}
