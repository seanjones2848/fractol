/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:54 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 19:18:46 by rlevine          ###   ########.fr       */
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
		julia(2);
	else if (ft_strcmp(av[1], "julia3") == 0)
		julia(3);
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		mandelbrot(2);
	else if (ft_strcmp(av[1], "mandelbrot3") == 0)
		mandelbrot(3);
	else
		perror("usage: ./fractol [julia, julia3, mandelbrot, mandelbrot3]\n");	return (0);
	s = init_super(1);
	mlx_loop(s->w->mlx);
}
