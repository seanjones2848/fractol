/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:43:15 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 13:41:51 by sjones           ###   ########.fr       */
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
	if (!s->i->space && s->m->t == 'j')
	{
		s->i->m_x = x + s->w->w / 2;
		s->i->m_y = y + s->w->h / 2;
		s->i->draw = true;
	}
	return (0);
}

int		loop_hook(t_super *s)
{
	if (s->i->draw == true)
	{
		fract(s);
		s->i->draw = false;
	}
	if (s->i->up)
		move(up, s);
	if (s->i->down)
		move(down, s);
	if (s->i->left)
		move(left, s);
	if (s->i->right)
		move(right, s);
	if (s->i->c)
		shift_color(s);
	if (s->i->x)
		revert(s);
	if (s->i->esc)
		exit(0);
	return (0);
}
