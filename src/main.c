/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:54 by sjones            #+#    #+#             */
/*   Updated: 2017/11/09 12:58:00 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Valid maps: julia, julia3, mandelbrot, mandelbrot3\n", 51);
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
		write(1, "Valid maps: julia, julia3, mandelbrot, mandelbrot3\n", 51);
	return (0);
}
