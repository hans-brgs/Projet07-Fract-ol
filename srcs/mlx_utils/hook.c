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
	// mlx_clear_window (win->mlx, win->mlx_win);
	julia_draw (win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img->mlx_img, 0, 0);
  	draw_user_interface (win);
	return;
}


int key_hook(int keycode, t_win *win)
{
	(keycode == UP) ? win->moveY += 0.02*win->zoom : 0;
	(keycode == DOWN) ? win->moveY -= 0.02*win->zoom : 0;
	(keycode == LEFT) ? win->moveX -= 0.02*win->zoom : 0;
	(keycode == RIGHT) ? win->moveX += 0.02*win->zoom : 0;
	(keycode == PLUS) ? win->It_incr += 10 : 0;
	(keycode == MINUS) ? win->It_incr -= 10 : 0;
	exec_ctrl(win);
	return(0);
}

int	mouse_click(int button, int x, int y, t_win *win)
{
	(button == 4) ? win->zoom /= 0.9 : 0;
	(button == 5) ? win->zoom *= 0.9 : 0;
	exec_ctrl(win);
	return (0);
}