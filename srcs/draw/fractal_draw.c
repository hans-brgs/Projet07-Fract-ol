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

static int	fractal_selection(t_win *win, t_complex cplx, int i)
{
	if (win->select == 1)
		i = julia_computation(win, cplx);
	else if (win->select == 2)
	{
		i = julia_computation(win, cplx);
		set_julia(win, 0.285, 0.01);
	}	
	else if (win->select == 3)
		i = mandelbrot_computation(win, cplx);
	else if (win->select == 4)
		i = burningship_computation(win, cplx);
	return (i);
}

static t_complex	map(t_win *win)
{
	int			l;
	t_complex	cplx;

	if (win->img->w < win->img->h)
		l = win->img->w;
	else
		l = win->img->h;
	cplx.Re = (3 * (win->zoom) * (win->img->x
				- win->img->w / 2.0) / l) + win->moveX;
	cplx.Im = (3 * win->zoom * (win->img->y
				- win->img->h / 2.0) / l) + win->moveY;
	return (cplx);
}

void	draw_fractal(t_win *win)
{
	int			i;
	int			color;
	t_complex	cplx;

	while (win->img->x < win->img->w)
	{
		win->img->y = 0;
		while (win->img->y < win->img->h)
		{
			cplx = map(win);
			i = fractal_selection(win, cplx, i);
			color = color_fractal(win, i);
			my_mlx_pixel_put(win->img, win->img->x, win->img->y, color);
			win->img->y++;
		}
		win->img->x++;
	}
	mlx_put_image_to_window(win->mlx, win->ptr, win->img->mlx_img, 0, 0);
}
