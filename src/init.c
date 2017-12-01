/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:37:46 by sjones            #+#    #+#             */
/*   Updated: 2017/12/01 13:39:37 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_win	*init_win(void)
{
	t_win	*w;

	if (!(w = (t_win*)malloc(sizeof(t_win))))
	{
		write(1, "malloc failed on t_win\n", 23);
		exit(-1);
	}
	w->t = "Fract'ol";
	w->w = WIN_X;
	w->h = WIN_Y;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->w, w->h, w->t);
	return (w);
}

static t_input	*init_input(void)
{
	t_input	*i;

	if (!(i = ft_memalloc(sizeof(*i))))
	{
		write(1, "malloc failed on t_input\n", 25);
		exit(-1);
	}
	return (i);
}

static t_map	*init_map(char t, int p)
{
	t_map	*m;

	if (!(m = ft_memalloc(sizeof(*m))))
	{
		write(1, "malloc failed on t_map\n", 23);
		exit(-1);
	}
	m->t = t;
	m->p = p;
	m->sc = 8;
	m->c = 0xFFFFFF;
	m->i = INITIAL_I;
	m->zoom = 1.0;
	return (m);
}

static t_img	*init_img(t_win *w)
{
	t_img	*i;

	if (!(i = ft_memalloc(sizeof(*i))))
	{
		write(1, "malloc failed on t_img\n", 23);
		exit(-1);
	}
	i->img = mlx_new_image(w->mlx, w->w, w->h);
	i->data = (int*)mlx_get_data_addr(i->img, &i->bpp, &i->size, &i->e);
	i->size /= 4;
	return (i);
}

t_super			*init_super(char t, int p)
{
	t_super	*s;

	if (!(s = ft_memalloc(sizeof(*s))))
	{
		write(1, "malloc failed on t_super\n", 25);
		exit(-1);
	}
	s->w = init_win();
	s->i = init_input();
	s->m = init_map(t, p);
	s->img = init_img(s->w);
	return (s);
}
