/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:08:33 by sjones            #+#    #+#             */
/*   Updated: 2017/11/30 17:05:33 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			colorize(t_thread *t)
{
	return((int)(((float)t->ret / (float)t->i) * 0xFF) << t->sc ^ t->c);
}

void		shift_color(t_super *s)
{
	srand(time(NULL));
	s->m->sc = rand() % 16;
	s->m->c = rand() % 0xFFFFFF;
	s->i->draw = true;
}
