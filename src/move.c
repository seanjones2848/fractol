/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:02:59 by sjones            #+#    #+#             */
/*   Updated: 2017/11/30 15:52:12 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int dir, t_super *s)
{
	if (dir == up)
		s->m->sy -= 10 * 1 / s->m->zoom;
	else if (dir == down)
		s->m->sy += 10 * 1 / s->m->zoom;
	else if (dir == left)
		s->m->sx -= 10 * 1 / s->m->zoom;
	else if (dir == right)
		s->m->sx += 10 * 1 / s->m->zoom;
	s->i->draw = true;
}
