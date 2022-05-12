/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:28:36 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 19:28:36 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_computation(t_win *win, t_complex cplx)
{
	int i;
	
	i = 0;
	julia_init(win);
	while (i < win->curr_fract->it_max + win->It_incr)
	{
		win->curr_fract->Z0 = add_cpx(sqr_cpx(cplx), win->curr_fract->c);
		cplx =win->curr_fract->Z0;
		if ((sqr(cplx.Re) + sqr(cplx.Im)) > 4)
			break;
		i++;
	}
	return (i);
}

int mandelbrot_computation(t_win *win, t_complex cplx)
{
	int i;
	
	i = 0;
	mandelbrot_init(win);
	while (i < win->curr_fract->it_max + win->It_incr)
	{
		win->curr_fract->Z0 = add_cpx(sqr_cpx(win->curr_fract->Z1), cplx);
		win->curr_fract->Z1 =win->curr_fract->Z0;
		if ((sqr(win->curr_fract->Z1.Re) + sqr(win->curr_fract->Z1.Im)) > 4)
			break;
		i++;
	}
	return (i);
}

int burningship_computation(t_win *win, t_complex cplx)
{
	int i;
	double squaredX;
	double squaredY;
	
	i = 0;
	mandelbrot_init(win);
	while (i < win->curr_fract->it_max + win->It_incr)
	{	
		win->curr_fract->Z0 = add_cpx(sqr_cpx_abs(win->curr_fract->Z1), cplx);
		win->curr_fract->Z1 =win->curr_fract->Z0;
		if ((sqr(win->curr_fract->Z1.Re) + sqr(win->curr_fract->Z1.Im)) > 4)
			break;
		i++;
	}
	return (i);
}