/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:07:58 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 12:07:58 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *) dst = color;
}

void	render(t_win *win)
{
	if (!win)
		return ;
	if (win->img)
		img_init(win, win->img, H, W);
	draw_fractal (win);
	draw_user_interface(win);
	return ;
}
