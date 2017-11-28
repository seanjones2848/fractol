/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:01:49 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 13:22:43 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int dir, t_super *s)
{
	if (dir == in)
	{
		s->m->x_max *= ZIN;
		s->m->x_min *= ZIN;
		s->m->y_max *= ZIN;
		s->m->y_min *= ZIN;
		printf("trying to zoom in\n");
	}
	else if (dir == out)
	{
		if (s->m->x_max < 2)
			s->m->x_max *= ZOUT;
		if (s->m->x_min > -2)
			s->m->x_min *= ZOUT;
		if (s->m->y_max < 2)
			s->m->y_max *= ZOUT;
		if (s->m->y_min > -2)
			s->m->y_min *= ZOUT;
		printf("trying to zoom out\n");
	}
	if (dir >= up && dir <= down)
		s->i->draw = true;
}
