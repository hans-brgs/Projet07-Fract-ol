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

t_complex sqr_cpx_abs(t_complex z)
{
	t_complex	new;

	new.Re = sqr(z.Re) - sqr(z.Im);
	new.Im = 2 * fabs(z.Re * z.Im);
	return (new);
}

t_complex add_cpx(t_complex z, t_complex c)
{
	t_complex	new;

	new.Re = z.Re + c.Re;
	new.Im = z.Im + c.Im;
	return (new);
}

