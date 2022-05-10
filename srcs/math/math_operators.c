/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:35:32 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/04 14:35:32 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double sqr(double num)
{
	double	sqr;

	sqr = num * num;
	return (sqr);
}

t_complex sqr_cpx(t_complex z)
{
	t_complex	new;

	new.Re = sqr(z.Re) - sqr(z.Im);
	new.Im = 2 * z.Re * z.Im;
	return (new);
}

t_complex add_cpx(t_complex z, t_complex c)
{
	t_complex	new;

	new.Re = z.Re + c.Re;
	new.Im = z.Im + c.Im;
	return (new);
}


double euclidean_dist(int x1, int x2, int y1, int y2)
{
	double dist;

	dist = sqrt(sqr(x2-x1) + sqr(y2-y1));
	return (dist);
}

double slope(int x1, int x2, int y1, int y2)
{
	double slope;
	ft_printf("(%d - %d) / (%d - %d)", y2, y1, x2, x1);
	slope = ((double) y2 - (double) y1) / ((double) x2 - (double) x1);
	return (slope);
}
