/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:28:17 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/10 13:28:17 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void free_str(t_win *win)
{
	(win->julia) ? free(win->img) : 0;
	(win->img) ? free(win->img) : 0;
	(win->ui1) ? free(win->img) : 0;
	(win->ui2) ? free(win->img) : 0;
}

void exit_error(t_win *win, char *str)
{
	free_str(win);
	printf("%s\n", str);
}