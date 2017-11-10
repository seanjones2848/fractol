/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 14:57:48 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, double complex deg)
{
	double complex	z;
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

int main()
{
	double complex deg = 3;
	double x, y;
	float inc = .0000005;

	x = y = 0;
	while (x < 1)
	{
		printf("The ret is: %d\n The xy is : %f \n", julia(x, y, deg), y);
		x += inc;
		y += inc;
	}
}
