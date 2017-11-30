/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:02:59 by sjones            #+#    #+#             */
/*   Updated: 2017/11/29 17:05:23 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int dir, t_super *s)
{
	if (dir == up)
		s->m->sy -= 0.1;
	else if (dir == down)
		s->m->sy += 0.1;
	else if (dir == left)
		s->m->sx -= 0.1;
	else if (dir == right)
		s->m->sx += 0.1;
	s->i->draw = true;
}
