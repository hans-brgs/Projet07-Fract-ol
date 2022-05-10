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

void julia_init(t_fract *fractol)
{
	fractol->it_max = 50;
	fractol->c.Re = -0.7;
	fractol->c.Im = 0.27015;
}

static void map(t_win *win, t_img *img, t_fract *fractol)
{
	int l;

	l = (img->w < img->h) ? img->w : img->h;
	// fractol->Z1.Re = (2 * (win->zoom) * (img->x - img->w / 2.0) / l) + win->moveX;
	// fractol->Z1.Im = (2 * win->zoom * (img->y - img->h / 2.0) / l) + win->moveY;
	fractol->Z1.Re = 1.5 * (img->x - img->w / 2.0) / (0.5 * win->zoom * img->w) + win->moveX;
	fractol->Z1.Im = (img->y - img->h / 2.0) / (0.5 * win->zoom * img->h) + win->moveY;
}

t_img *julia_draw(t_win *win)
{
	t_img *img;
	t_fract *julia;
	int i;
	int color;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
	  return (NULL);
	img_init (win, img, HEIGHT, WIDTH);
	if (!(julia = (t_fract *)malloc(sizeof(t_fract))))
		return (NULL);
	julia_init (julia);
	while (img->x < img->w)
	{
		img->y = 0;
		while (img->y < img->h)
		{
			map(win, img, julia);
			i = julia_computation(julia);
			color = color_fractol(win, julia, i);
			my_mlx_pixel_put(img, img->x, img->y, color);
			img->y++;
		}
		img->x++;
	}
	return (img);
}