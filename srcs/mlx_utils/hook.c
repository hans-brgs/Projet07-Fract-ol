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

static void	key_move(int keycode, t_win *win)
{
	if (keycode == UP)
		win->move_y -= 0.01 * win->zoom;
	if (keycode == DOWN)
		win->move_y += 0.01 * win->zoom;
	if (keycode == LEFT)
		win->move_x -= 0.01 * win->zoom;
	if (keycode == RIGHT)
		win->move_x += 0.01 * win->zoom;
	if (keycode == PLUS)
		win->it_incr += 6;
	if (keycode == MINUS)
		win->it_incr -= 6;
}

static void	key_transform(int keycode, t_win *win)
{
	if (keycode == NUMPAD_1)
		win->select = 1;
	if (keycode == NUMPAD_2)
		win->select = 3;
	if (keycode == NUMPAD_3)
		win->select = 4;
	if (keycode == COLOR)
		win->color += 1;
	if (keycode == CLEAR)
		reset_fractal(win);
	if (keycode == ESCAPE)
		close_and_free(win);
	if (win->select == 1 && keycode == MUTATE)
		julia_transform(win);
}

int	key_hook(int keycode, t_win *win)
{
	key_move(keycode, win);
	key_transform(keycode, win);
	render(win);
	return (0);
}

int	mouse_click(int button, int x, int y, t_win *win)
{
	if (button == 4)
		win->zoom /= 0.9;
	if (button == 5)
		win->zoom *= 0.9;
	render(win);
	return (0);
}

int	close_and_free(t_win *win)
{
	free_str(win);
	exit(0);
}
