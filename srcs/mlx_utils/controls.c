/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:04:52 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 19:04:52 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set_julia(t_win *win, double cRe, double cIm)
{
	win->julia_cRe = cRe;
	win->julia_cIm = cIm;
}

void reset_fractal(t_win *win)
{
	win->zoom = 1;
	win->moveX = 0;
	win->moveY = 0;
	win->It_incr = 0;
	win->mutate_julia = 1;
	set_julia(win, -0.7, 0.27015);
}

void julia_transform(t_win *win)
{
	win->mutate_julia += 1;
	if (win->mutate_julia < 7)
	{
		(win->mutate_julia == 1) ? set_julia(win, -0.7, 0.27015) : 0;
		(win->mutate_julia == 2) ? set_julia(win, -0.4, 0.6) : 0;
		(win->mutate_julia == 3) ? set_julia(win, 0.285, 0.01) : 0;
		(win->mutate_julia == 4) ? set_julia(win, 0, -0.8) : 0;
		(win->mutate_julia == 5) ? set_julia(win, 1- (1 + sqrt(5)) / 2, 0) : 0;
		(win->mutate_julia == 6) ? set_julia(win, -333 / 235, 47 / 4722 ) : 0;
	}
	else
	{
		win->mutate_julia = 1;
		set_julia(win, -0.7, 0.27015);
	}
}

