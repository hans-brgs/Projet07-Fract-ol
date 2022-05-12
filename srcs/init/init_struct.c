/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:56 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 08:52:56 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_component(t_win *win)
{
	win->curr_fract = malloc(sizeof(t_fract));
	if (!win->curr_fract)
		exit_error(win, "malloc fail");
	win->img = malloc(sizeof(t_img));
	if (!win->img)
		exit_error(win, "malloc fail");
	win->ui1 = malloc(sizeof(t_img));
	if (!(win->ui1))
		exit_error(win, "malloc fail");
	win->ui2 = malloc(sizeof(t_img));
	if (!(win->ui2))
		exit_error(win, "malloc fail");
	win->ui3 = malloc(sizeof(t_img));
	if (!(win->ui3))
		exit_error(win, "malloc fail");
}

void	win_init(t_win *win)
{
	malloc_component(win);
	win->h = H;
	win->w = W;
	win->zoom = 1;
	win->move_x = 0;
	win->move_y = 0;
	win->x = 0;
	win->y = 0;
	win->select = 2;
	win->curr_fract->it_max = 6;
	win->mutate_julia = 1;
	win->julia_c_re = -0.7;
	win->julia_c_im = 0.27015;
	win->color = 1;
	win->mlx = mlx_init();
	win->ptr = mlx_new_window(win->mlx, win->w, win->h, "Fractal explorer");
}

void	img_init(t_win *win, t_img *img, int h, int w)
{
	img->h = h;
	img->w = w;
	img->x = 0;
	img->y = 0;
	img->mlx_img = mlx_new_image(win->mlx, img->w, img->h);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	julia_init(t_win *win)
{
	win->curr_fract->c.re = win->julia_c_re;
	win->curr_fract->c.im = win->julia_c_im;
}

void	mandelbrot_init(t_win *win)
{
	win->curr_fract->z1.re = 0.0;
	win->curr_fract->z1.im = 0.0;
}
