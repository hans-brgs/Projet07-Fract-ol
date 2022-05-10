/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:56:08 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 18:56:08 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void exec_ctrl(t_win *win)
{
	t_img *img;

	// mlx_clear_window (win->mlx, win->mlx_win);
	img = julia_draw (win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img->mlx_img, 0, 0);
  	draw_user_interface (win);
	return;
}


int key_hook(int keycode, t_win *win)
{
	(keycode == UP) ? win->moveY += 0.01 : 0;
	(keycode == DOWN) ? win->moveY -= 0.01 : 0;
	(keycode == LEFT) ? win->moveX -= 0.01 : 0;
	(keycode == RIGHT) ? win->moveX += 0.01 : 0;
	(keycode == PLUS) ? win->It_incr += 1 : 0;
	(keycode == MINUS) ? win->It_incr -= 1 : 0;
	exec_ctrl(win);
	return(0);
}

int	mouse_click(int button, int x, int y, t_win *win)
{
	// if (button == 1)
	// 	mouse_left_click(x, y, core);
	if (button == 4)
		zoom_in(win);
	// if (button == 5 && (x >= 380 && x <= 1660) && (y >= 180 && y <= 900))
	// 	zoom(x - 382, y - 180, &core->ctx->view, 1 / 1.1f);
	// if (button == 3)
	// 	core->mouse.mid_down = true;
	exec_ctrl(win);
	// render(core);
	return (0);
}