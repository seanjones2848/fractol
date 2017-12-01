/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:09:33 by sjones            #+#    #+#             */
/*   Updated: 2017/12/01 13:22:55 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int key, t_super *s)
{
	if (key == KEY_C)
		shift_color(s);
	if (key == KEY_X)
		revert(s);
	if (key == KEY_W || key == KEY_UP)
		s->i->up = true;
	if (key == KEY_S || key == KEY_DOWN)
		s->i->down = true;
	if (key == KEY_A || key == KEY_LEFT)
		s->i->left = true;
	if (key == KEY_D || key == KEY_RIGHT)
		s->i->right = true;
	if (key == KEY_ESCAPE)
		s->i->esc = true;
	if (key == KEY_SPACEBAR)
		s->i->space = s->i->space == true ? (false) : (true);
	if (key == KEY_F && (s->i->draw = true))
		s->m->t = s->m->t == 'm' ? ('j') : ('m');
	if (key == KEY_P && (s->i->draw = true))
		s->m->p = s->m->p == 2 ? (3) : (2);
	return (0);
}

int		key_release(int key, t_super *s)
{
	if (key == KEY_W || key == KEY_UP)
		s->i->up = false;
	if (key == KEY_S || key == KEY_DOWN)
		s->i->down = false;
	if (key == KEY_A || key == KEY_LEFT)
		s->i->left = false;
	if (key == KEY_D || key == KEY_RIGHT)
		s->i->right = false;
	if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		mouse_press(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT && s->m->i <= MAX_I && (s->i->draw = true))
		s->m->i += 4;
	if (key == MOUSE_RIGHT && s->m->i >= 4 && (s->i->draw = true))
		s->m->i -= 4;
	if (key == MOUSE_SCROLL_UP)
		zoom(in, s);
	if (key == MOUSE_SCROLL_DOWN)
		zoom(out, s);
	return (x + y);
}

int		mouse_release(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT)
		s->i->m_l = false;
	if (key == MOUSE_RIGHT)
		s->i->m_r = false;
	if (key == MOUSE_SCROLL_UP)
		s->i->m_su = false;
	if (key == MOUSE_SCROLL_DOWN)
		s->i->m_sd = false;
	return (x + y);
}
