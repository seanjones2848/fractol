/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 15:43:45 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fract(double x, double y, double complex deg, double complex z)
{
	int				ret;
	int				maxloop = 100;
	double complex	c;

	c = x + y * I;
	ret = 0;
	z = 0;
	while (cabs(z) < 2 && ret < maxloop)
	{
		z = cpow(z, deg) + c;
		ret ++;
	}
	return ret;
}
