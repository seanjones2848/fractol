/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:38:25 by sjones            #+#    #+#             */
/*   Updated: 2017/12/01 13:38:27 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_super	*fractol_choice(char *s)
{
	if (ft_strcmp(s, "julia") == 0)
		return (init_super('j', 2));
	else if (ft_strcmp(s, "julia3") == 0)
		return (init_super('j', 3));
	else if (ft_strcmp(s, "mandelbrot") == 0)
		return (init_super('m', 2));
	else if (ft_strcmp(s, "mandelbrot3") == 0)
		return (init_super('m', 3));
	return (NULL);
}

void			revert(t_super *s)
{
	s->m->zoom = 1.0;
	s->m->sx = 0.0;
	s->m->sy = 0.0;
	s->m->i = INITIAL_I;
}

int				main(int ac, char **av)
{
	t_super	*s;

	if (ac != 2)
	{
		perror("usage: ./fractol [julia, julia3, mandelbrot, mandelbrot3]\n");
		return (0);
	}
	if (!(s = fractol_choice(av[1])))
	{
		perror("usage: ./fractol [julia, julia3, mandelbrot, mandelbrot3]\n");
		return (0);
	}
	mlx_hook(s->w->win, 2, 0, key_press, s);
	mlx_hook(s->w->win, 3, 0, key_release, s);
	mlx_hook(s->w->win, 4, 0, mouse_press, s);
	mlx_hook(s->w->win, 5, 0, mouse_release, s);
	mlx_hook(s->w->win, 6, 0, motion_hook, s);
	mlx_hook(s->w->win, 12, 0, expose_hook, s);
	mlx_loop_hook(s->w->mlx, loop_hook, s);
	mlx_loop(s->w->mlx);
	return (0);
}
