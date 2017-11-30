/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/29 16:56:52 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	colorize(int i, t_super *s)
{
	return((int)(((float)i / (float)s->m->i) * 255) << 16 | 0xFF);
}

int			draw(t_super *s)
{
	mlx_put_image_to_window(s->w->mlx, s->w->win, s->img->img, 0, 0);
	return (1);
}

void		revert(t_super *s)
{
	s->m->zoom = 1.0;
	s->m->sx = 0.0;
	s->m->sy = 0.0;
	s->m->i = 16;
}

static void	inner_fract(t_super *s)
{
	s->m->nre = 1.5 * (s->m->px - s->w->w / 2) / (0.5 * s->m->zoom * s->w->w) + s->m->sx;
	s->m->nim = (s->m->py - s->w->h / 2) / (0.5 * s->m->zoom * s->w->h) + s->m->sy;
	while (fabs(s->m->nre * s->m->nre + s->m->nim * s->m->nim) < 4.0 && s->m->ret < s->m->i)
	{
		s->m->ore = s->m->nre;
		s->m->oim = s->m->nim;
		s->m->nre = s->m->ore * s->m->ore - s->m->oim * s->m->oim + s->m->cre;
		s->m->nim = 2 * s->m->ore * s->m->oim + s->m->cim;
		s->m->ret++;
	}
}

int			fract(t_super *s)
{

	s->m->px = 0;
	while (s->m->px < s->w->w)
	{
		s->m->py = 0;
		while (s->m->py < s->w->h)
		{
			s->m->ret = 0;
			inner_fract(s);
			s->img->data[s->m->px + (s->img->size * s->m->py)]
				= colorize(s->m->ret, s);
			s->m->py++;
		}
		s->m->px++;
	}
	return(draw(s));
}
