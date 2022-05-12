/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:01:40 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 17:01:40 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	user_interface_txt(t_win win)
{
	int	c;

	c = rgb_to_int(225, 225, 225);
	mlx_string_put(win.mlx, win.ptr, 20, 25, c, "Controls Keys");
	mlx_string_put(win.mlx, win.ptr, 17, 53, c, "Move = ^ v < >");
	mlx_string_put(win.mlx, win.ptr, 17, 73, c, "Zoom = scroll");
	mlx_string_put(win.mlx, win.ptr, 17, 93, c, "Iter = + | -");
	mlx_string_put(win.mlx, win.ptr, 17, 113, c, "Reset = del");
	mlx_string_put(win.mlx, win.ptr, 17, H - 85, c, "Fract explorer");
	mlx_string_put(win.mlx, win.ptr, 17, H - 58, c, "Julia = 1");
	mlx_string_put(win.mlx, win.ptr, 17, H - 38, c, "Mandelbrot = 2");
	mlx_string_put(win.mlx, win.ptr, 17, H - 18, c, "BurningShip = 3");
	mlx_string_put(win.mlx, win.ptr, W - 127, H - 65, c, "Fract transformer");
	mlx_string_put(win.mlx, win.ptr, W - 127, H - 38, c, "Color = c");
	mlx_string_put(win.mlx, win.ptr, W - 127, H - 18, c, "Mutate Julia = j");
	return;
}

void	fill_image (t_img *img)
{
	int	color1;
	int	color2;

	color1 = rgb_to_int(25, 25, 25);
	color2 = rgb_to_int(135, 135, 135);
	while (img->x < img->w)
	{
		img->y = 0;
		while (img->y < img->h)
		{
			if (img->y == 0)
				my_mlx_pixel_put (img, img->x, img->y, color2);
			else if (img->x == 0)
				my_mlx_pixel_put (img, img->x, img->y, color2);
			else if (img->x == img->w - 1)
				my_mlx_pixel_put (img, img->x, img->y, color2 * 0.4);
			else if (img->y == img->h - 1)
				my_mlx_pixel_put (img, img->x, img->y, color2 * 0.4);
			else
				my_mlx_pixel_put (img, img->x, img->y, color1);
			img->y++;
		}
		img->x++;
	}
	return;
}

int	draw_user_interface (t_win *win)
{
	img_init(win, win->ui1, 115, 95);
	img_init(win, win->ui2, 95, 105);
	img_init(win, win->ui3, 75, 115);
	fill_image(win->ui1);
	fill_image(win->ui2);
	fill_image(win->ui3);
	mlx_put_image_to_window(win->mlx, win->ptr, win->ui1->mlx_img, 10, 10);
	mlx_put_image_to_window(win->mlx, win->ptr, win->ui2->mlx_img, 10, H - 100);
	mlx_put_image_to_window(win->mlx, win->ptr, win->ui3->mlx_img, W - 135, H - 80);
	user_interface_txt(*win);
	return (0);
}
