/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:36 by sjones            #+#    #+#             */
/*   Updated: 2017/11/29 16:51:34 by sjones           ###   ########.fr       */
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
	w->win = mlx_new_window(w->mlx, w->w, w->h, w->t);
	return (w);
}

static t_input	*init_input(void)
{
	t_input	*i;

	if (!(i = (t_input*)malloc(sizeof(t_input))))
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

	if (!(m = (t_map*)malloc(sizeof(t_map))))
	{
		write(1, "malloc failed on t_map\n", 23);
		return NULL;
	}
	ft_bzero(m, sizeof(t_map));
	m->t = t;
	m->p = p;
	m->i = INITIAL_I;
	m->cre = -0.7;
	m->cim = 0.27015;
	m->zoom = 1.0;
	return (m);
}

static t_img	*init_img(t_win *w)
{
	t_img	*i;

	if (!(i = (t_img*)ft_memalloc(sizeof(t_img))))
	{
		write(1, "malloc failed on t_img\n", 23);
		return NULL;
	}
	i->img = mlx_new_image(w->mlx, w->w, w->h);
	i->data = (int*)mlx_get_data_addr(i->img, &i->bpp, &i->size, &i->e);
	i->size /= 4;
	return (i);
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
	s->i = init_input();
	s->m = init_map(t, p);
	s->img = init_img(s->w);
	return (s);
}
