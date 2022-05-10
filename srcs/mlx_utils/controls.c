/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:04:52 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 19:04:52 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom_in(t_win *win)
{
	win->zoom = win->zoom / 0.9;
}

void zoom_out(t_win *win)
{
	win->zoom = win->zoom * 0.9;
}

void moove(t_win *win, size_t dir)
{
	(dir == 1) ? win->moveY += 0.01 : 0;
	(dir == 2) ? win->moveY -= 0.01 : 0;
	(dir == 3) ? win->moveX -= 0.01 : 0;
	(dir == 4) ? win->moveX += 0.01 : 0;
}

void moove_rigth(t_win *win)
{
	win->moveX += 0.01;
}