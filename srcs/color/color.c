/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 09:27:21 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/08 09:27:21 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int static	color_init(t_win *win, int i, float mod)
{
	int	c;

	c = (int)(i * mod) % (win->curr_fract->it_max)
		/ (float)(win->curr_fract->it_max - 1) * 255;
	return (c);
}

int static	palette(t_win *win, int r, int g, int b)
{
	int	color;

	if (win->color == 1)
		color = rgb_to_int(r, 0, 0);
	else if (win->color == 2)
		color = rgb_to_int(0, r, 0);
	else if (win->color == 3)
		color = rgb_to_int(0, 0, r);
	else if (win->color == 4)
		color = rgb_to_int(r, r, 0);
	else if (win->color == 5)
		color = rgb_to_int(0, r, r);
	else if (win->color == 6)
		color = rgb_to_int(r, 0, r);
	else if (win->color == 7)
		color = rgb_to_int(r, g, b);
	else
		color = 0;
	return (color);
}

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = ((int)r << 16) | ((int)g << 8) | ((int)b);
	return (color);
}

int	color_fractal(t_win *win, int i)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = color_init(win, i, 29);
	g = color_init(win, i, 1.5);
	b = color_init(win, i, 49);
	if (win->color < 8)
		color = palette(win, r, g, b);
	else
	{
		win->color = 1;
		color = rgb_to_int(r, 0, 0);
	}
	return (color);
}
