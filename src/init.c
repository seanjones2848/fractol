/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:06:36 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 19:20:02 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_super			*init_super(int p)
{
	t_super	*s;

	if (!(s = (t_super*)malloc(sizeof(t_super))))
	{
		write(1, "malloc failed on t_super\n", 25);
		return NULL;
	}
	s->w = init_win(void);
	s->k = init_keys(void);
	s->m = init_map(p);
}

static t_win	*init_win(void)
{
	t_win *w;

	if(!(w = (t_win*)malloc(sizeof(t_win))))
	{
		write(1, "malloc failed on t_win\n", 23);
		return NULL;
	}
	w->t = "Fract'ol";
	w->w = WIN_X;
	w->h = WIN_Y;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->w, w->h, win->t);
}
