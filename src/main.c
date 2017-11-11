/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:54 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 21:19:39 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_super	*s;

	if (ac != 2)
	{
		perror("usage: ./fractol [julia, julia3, mandelbrot, mandelbrot3]\n");
		return (0);
	}
	if (ft_strcmp(av[1], "julia") == 0)
		s = init_super('j', 2);
	else if (ft_strcmp(av[1], "julia3") == 0)
		s = init_super('j', 3);
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		s = init_super('m', 2);
	else if (ft_strcmp(av[1], "mandelbrot3") == 0)
		s = init_super('m', 3);
	else
	{
		perror("usage: ./fractol [julia, julia3, mandelbrot, mandelbrot3]\n");
		return (0);
	}
	fract(s);
//	draw(s);
//	mlx_loop(s->w->mlx);
	return (0);
}
