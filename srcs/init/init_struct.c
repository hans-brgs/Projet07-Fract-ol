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

void win_init(t_win *win)
{
	win->h = HEIGHT;
	win->w = WIDTH;
	win->zoom = 1;
	win->moveX = 0;
	win->moveY = 0;
	win->x = 0;
	win->y = 0;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->w, win->h, "Test");
}

void img_init(t_win *win, t_img *img, int h, int w)
{
	img->h = h;
	img->w = w;
	img->x = 0;
	img->y = 0;
	img->mlx_img = mlx_new_image(win->mlx, img->w, img->h);
	img->addr =  mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}
