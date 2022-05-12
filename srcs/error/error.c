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

void	free_str(t_win *win)
{
	if (win)
	{
		mlx_destroy_image(win->mlx, win->img->mlx_img);
		mlx_destroy_image(win->mlx, win->ui1->mlx_img);
		mlx_destroy_image(win->mlx, win->ui2->mlx_img);
		mlx_destroy_image(win->mlx, win->ui3->mlx_img);
		mlx_destroy_window(win->mlx, win->ptr);
		free(win->curr_fract);
		free(win->img);
		free(win->ui1);
		free(win->ui2);
		free(win->ui3);
		free(win);
	}
}

void	exit_error(t_win *win, char *str)
{
	free_str(win);
	ft_printf("%s\n", str);
}
