/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:37:58 by sjones            #+#    #+#             */
/*   Updated: 2017/12/01 17:40:30 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	inner_fract(t_thread *t)
{
	t->cre = t->t == 'm' ? ((t->px - t->w / 2) / (0.25 * t->zoom * t->w)
			+ t->sx / t->w) : (t->m_x * 0.001);
	t->cim = t->t == 'm' ? ((t->py - t->h / 2) / (0.25 * t->zoom * t->h)
			+ t->sy / t->h) : (t->m_y * 0.001);
	t->nre = t->t == 'm' ? (0) : ((t->px - t->w / 2) /
			(0.25 * t->zoom * t->w) + t->sx / t->w);
	t->nim = t->t == 'm' ? (0) : ((t->py - t->h / 2) / (0.25 * t->zoom * t->h)
			+ t->sy / t->h);
	while (fabs(t->nre * t->nre + t->nim * t->nim) < 4.0 && t->ret < t->i)
	{
		t->ore = t->nre;
		t->oim = t->nim;
		t->nre = t->p == 2 ? (t->ore * t->ore - t->oim * t->oim + t->cre) :
			(t->ore * (t->ore * t->ore - 3 * t->oim * t->oim) + t->cre);
		t->nim = t->p == 2 ? (2 * t->ore * t->oim + t->cim) :
			(t->oim * (3 * t->ore * t->ore - t->oim * t->oim) + t->cim);
		t->ret++;
	}
}

static void	fract_it(t_thread *t)
{
	t->px = t->w / THREADS * (t->id - 1);
	while (t->px < t->w / THREADS * (t->id))
	{
		t->py = 0;
		while (t->py < t->h)
		{
			t->ret = 0;
			inner_fract(t);
			t->data[t->px + (t->size * t->py)] = colorize(t);
			t->py++;
		}
		t->px++;
	}
}

t_thread	*init_thread(t_super *s, int i)
{
	t_thread	*t;

	t = ft_memalloc(sizeof(*t));
	t->id = i;
	t->cre = s->m->cre;
	t->cim = s->m->cim;
	t->t = s->m->t;
	t->p = s->m->p;
	t->c = s->m->c;
	t->sc = s->m->sc;
	t->i = s->m->i;
	t->zoom = s->m->zoom;
	t->sx = s->m->sx;
	t->sy = s->m->sy;
	t->h = s->w->h;
	t->w = s->w->w;
	t->m_x = s->i->m_x;
	t->m_y = s->i->m_y;
	t->data = s->img->data;
	t->size = s->img->size;
	return (t);
}

static void	*fract_runner(void *v)
{
	t_thread		*t;

	t = (t_thread*)v;
	fract_it(t);
	free(t);
	pthread_exit(0);
}

int			fract(t_super *s)
{
	pthread_t	tids[THREADS];
	t_thread	*t;
	int			i;

	i = 0;
	while (i < THREADS)
	{
		t = init_thread(s, i + 1);
		pthread_create(&tids[i], NULL, fract_runner, t);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
	mlx_put_image_to_window(s->w->mlx, s->w->win, s->img->img, 0, 0);
	return (1);
}
