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

int key_hook(int keycode, t_win *win)
{
	(keycode == UP) ? win->moveY -= 0.01*win->zoom : 0;
	(keycode == DOWN) ? win->moveY += 0.01*win->zoom : 0;
	(keycode == LEFT) ? win->moveX -= 0.01*win->zoom : 0;
	(keycode == RIGHT) ? win->moveX += 0.01*win->zoom : 0;
	(keycode == PLUS) ? win->It_incr += 6 : 0;
	(keycode == MINUS) ? win->It_incr -= 6 : 0;
	(keycode == NUMPAD_1) ? win->select = 1 : 0;
	(keycode == NUMPAD_2) ? win->select = 3 : 0;
	(keycode == NUMPAD_3) ? win->select = 4 : 0;
	(keycode == COLOR) ? win->color += 1 : 0;
	(keycode == CLEAR) ? reset_fractal(win) : 0;
	(keycode == ESCAPE) ? close_and_free(win) : 0;
	if (win->select == 1)
		(keycode == MUTATE) ? julia_transform(win) : 0;
	render(win);
	return(0);
}

int	mouse_click(int button, int x, int y, t_win *win)
{
	(button == 4) ? win->zoom /= 0.9 : 0;
	(button == 5) ? win->zoom *= 0.9 : 0;
	render(win);
	return (0);
}

int close_and_free(t_win *win)
{
	free_str(win);
	exit(0);
}