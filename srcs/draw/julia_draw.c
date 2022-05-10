/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:48:59 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/04 14:48:59 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void map(t_win *win)
{
	int l;

	l = (win->img->w < win->img->h) ? win->img->w : win->img->h;
	win->julia->Z1.Re = (2 * (win->zoom) * (win->img->x - win->img->w / 2.0) / l) + win->moveX;
	win->julia->Z1.Im = (2 * win->zoom * (win->img->y - win->img->h / 2.0) / l) + win->moveY;
	// win->julia->Z1.Re = 1.5 * (win->img->x - win->img->w / 2.0) / (0.5 * win->zoom * win->img->w) + win->moveX;
	// win->julia->Z1.Im = (win->img->y - win->img->h / 2.0) / (0.5 * win->zoom * win->img->h) + win->moveY;
}

void julia_draw(t_win *win)
{
	int i;
	int color;

	img_init(win, win->img, HEIGHT, WIDTH);
	// julia_init(win->julia);
	while (win->img->x < win->img->w)
	{
		win->img->y = 0;
		while (win->img->y < win->img->h)
		{
			map(win);
			i = julia_computation(win);
			color = color_fractol(win, i);
			my_mlx_pixel_put(win->img, win->img->x, win->img->y, color);
			win->img->y++;
		}
		win->img->x++;
	}
	return;
}