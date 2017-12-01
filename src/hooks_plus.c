/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:43:15 by sjones            #+#    #+#             */
/*   Updated: 2017/11/30 16:05:15 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_super *s)
{
	s->i->draw = true;
	return (0);
}

int		motion_hook(int x, int y, t_super *s)
{
	if (!s->i->space)
	{
		s->i->m_x = x - s->w->w / 2;
		s->i->m_y = y - s->w->h / 2;
		//s->i->draw = true;
	}
	return (0);
}

int		loop_hook(t_super *s)
{
	if (s->i->draw == true && fract(s))
		s->i->draw = false;
	if (s->i->up)
		move(up, s);
	if (s->i->down)
		move(down, s);
	if (s->i->left)
		move(left, s);
	if (s->i->right)
		move(right, s);
	return (0);
}
