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

int rgb_to_int(double r, double g, double b)
{
	int color = 0;
	color = ((int)r << 16) | ((int)g << 8) | ((int)b);
	return (color);
}

int color_fractol(t_win *win, int i)
{
	int r;
	int g;
	int b;
	int color;

	r = (i*9) % (win->julia->it_max) / (float)(win->julia->it_max - 1) * 255;
	g = (int)(i) % (win->julia->it_max) / (float)(win->julia->it_max - 1)*255;
	b = (int)(i) % (win->julia->it_max) / (float)(win->julia->it_max - 1) *255;
	color = rgb_to_int(r, 0, 0);
	return (color);
}