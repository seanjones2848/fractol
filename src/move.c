/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:02:59 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 13:05:19 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int dir, t_super *s)
{
	if (dir == up)
	{
		if (s->m->y_max < 2)
		{
			s->m->y_max += .1 * (ABS(s->m->y_max - s->m->y_min));
			s->m->y_min += .1 * (ABS(s->m->y_max - s->m->y_min));
		}
	}
	else if (dir == down)
	{
		if (s->m->y_min > -2)
		{
			s->m->y_max -= .1 * (ABS(s->m->y_max - s->m->y_min));
			s->m->y_min -= .1 * (ABS(s->m->y_max - s->m->y_min));
		}
	}
	else if (dir == left)
	{
		if (s->m->x_max < 2)
		{
			s->m->x_max += .1 * (ABS(s->m->x_max - s->m->x_min));
			s->m->x_min += .1 * (ABS(s->m->x_max - s->m->x_min));
		}
	}
	else if (dir == right)
	{
		if (s->m->x_min > -2)
		{
			s->m->x_max -= .1 * (ABS(s->m->x_max - s->m->x_min));
			s->m->x_min -= .1 * (ABS(s->m->x_max - s->m->x_min));
		}
	}
	if (dir >= up && dir <= right)
		s->i->draw = true;
}
