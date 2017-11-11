/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:08 by sjones            #+#    #+#             */
/*   Updated: 2017/11/10 19:53:55 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fract(t_super *s)
{
	int				ret;
	int				maxloop = 100;
	double complex	c;
	double			x;
	double			y;
	double complex	z;

	c = x + y * I;
	ret = 0;
	z = 0;
	while (cabs(z) < 2 && ret < maxloop)
	{
		z = cpow(z, (double complex)s->m->p) + c;
		ret ++;
	}
	return ret;
}
