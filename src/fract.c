/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 13:46:01 by sjones           ###   ########.fr       */
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
	s->m->x_max = 2;
	s->m->x_min = -2;
	s->m->y_max = 2;
	s->m->y_min = -2;
	s->m->i = 16;
}

int			fract(t_super *s)
{
	int				ret;

	s->m->x = s->m->x_min;
	s->m->px = 0;
	while (s->m->px < s->w->w)
	{
		s->m->py = 0;
		s->m->y = s->m->y_min;
		while (s->m->py < s->w->h)
		{
			ret = 0;
			s->m->z = (s->i->m_x * .001 + s->i->m_y * .001 * I);
			s->m->c = (s->m->x + s->m->y * I);
			while (cabs(s->m->z) < 2 && ret < s->m->i)
			{
				s->m->z = cpow(s->m->z, (double complex)s->m->p) + s->m->c;
				ret ++;
			}
			s->img->data[s->m->px + (s->img->size * s->m->py)] = colorize(ret, s);
			s->m->py++;
			s->m->y += (ABS(s->m->y_max - s->m->y_min)) / s->w->h;
		}
		s->m->px++;
		s->m->x += (ABS(s->m->x_max - s->m->x_min)) / s->w->w;
	}
	return(draw(s));
}
