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

double	sqr(double num)
{
	double	sqr;

	sqr = num * num;
	return (sqr);
}

t_complex	sqr_cpx(t_complex z)
{
	t_complex	new;

	new.re = sqr(z.re) - sqr(z.im);
	new.im = 2 * z.re * z.im;
	return (new);
}

t_complex	sqr_cpx_abs(t_complex z)
{
	t_complex	new;

	new.re = sqr(z.re) - sqr(z.im);
	new.im = 2 * fabs(z.re * z.im);
	return (new);
}

t_complex	add_cpx(t_complex z, t_complex c)
{
	t_complex	new;

	new.re = z.re + c.re;
	new.im = z.im + c.im;
	return (new);
}
