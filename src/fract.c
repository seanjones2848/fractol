/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 21:42:11 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	colorize(int i, t_super *s)
{
	printf("interations:{%d}\n", i);
	return((int)(((float)i / (float)s->m->i) * 255) << 16 | 0xFF);
}
/*
void		draw(t_super *s)
{
	
}
*/
void		fract(t_super *s)
{
	int				ret;

	s->m->x = s->m->x_min;
	while (s->m->px < s->w->w)
	{
		s->m->py = 0;
		s->m->y = s->m->y_min;
		while (s->m->py < s->w->h)
		{
			ret = 0;
			s->m->z = 0;
			s->m->c = (s->m->x + s->m->y * I);
			while (cabs(s->m->z) < 2 && ret < s->m->i)
			{
				s->m->z = cpow(s->m->z, (double complex)s->m->p) + s->m->c;
				ret ++;
			}
			s->m->map[s->m->px + s->m->py] = colorize(ret, s);
			printf("px:{%d} py:{%d} x:{%f} y:{%f} color:{0x%08x}\n",\
				s->m->px, s->m->py, s->m->x, s->m->y, s->m->map[s->m->px + s->m->py]);
			s->m->py++;
			s->m->y += (ABS(s->m->y_max - s->m->y_min)) / s->w->h;
		}
		s->m->px++;
		s->m->x += (ABS(s->m->x_max - s->m->x_min)) / s->w->w;
	}
}
