/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:08:33 by sjones            #+#    #+#             */
/*   Updated: 2017/11/30 16:40:06 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			colorize(t_thread *t)
{
/*	int		r;
	int		g;
	int		b;

	r = (int)(((float)t->ret / (float)t->i) * 255);
	g = r;
	b = r;
	if (t->i % 2 == 0)
		r = ABS(g - 255);
	if (t->i % 3 == 0)
		g = ABS(b - 255);
	if (t->i % 4 == 0)
		b = ABS(r - 255);
	return(r << 16 | g << 8 | 0xFF);
*/
	return((int)(((float)t->ret / (float)t->i) * 0xFF) << t->c | 0xFF);
}

void		shift_color(t_super *s)
{
	if (s->m->c < 16)
		s->m->c++;
	else
		s->m->c = 4;
	s->i->draw = true;
}
