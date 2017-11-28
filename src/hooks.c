/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:09:33 by sjones            #+#    #+#             */
/*   Updated: 2017/11/28 13:29:21 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int key, t_super *s)
{
	if (key == KEY_C)
		s->i->c = true;
	if (key == KEY_X)
		s->i->x = true;
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
		s->i->space = false;
	if (key)
		s->i->draw = true;
	return (0);
}

int		key_release(int key, t_super *s)
{
	if (key == KEY_C)
		s->i->c = false;
	if (key == KEY_X)
		s->i->x = false;
	if (key == KEY_W || key == KEY_UP)
		s->i->up = false;
	if (key == KEY_S || key == KEY_DOWN)
		s->i->down = false;
	if (key == KEY_A || key == KEY_LEFT)
		s->i->left = false;
	if (key == KEY_D || key == KEY_RIGHT)
		s->i->right = false;
	if (key == KEY_ESCAPE)
		s->i->esc = false;
	if (key == KEY_SPACEBAR)
		s->i->space = false;
	return(0);
}

int		mouse_press(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT && s->m->i <= MAX_I && (s->i->draw = true))
	{
		s->m->i += 4;
		printf("s->m->i{%d}\n", s->m->i);
	}
	if (key == MOUSE_RIGHT && s->m->i >= 4 && (s->i->draw = true))
	{
		s->m->i -= 4;
		printf("s->m->i{%d}\n", s->m->i);
	}
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
