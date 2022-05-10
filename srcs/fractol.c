/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:10:25 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/10 16:13:10 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
  t_img *img;
  t_win *win;
  
  if (!(win = (t_win *)malloc(sizeof(t_win))))
	  return (-1);
 
  win_init (win);
  // julia_draw (win);
  mlx_hook(win->mlx_win, 3, 1L<<1, key_hook, win);
  mlx_mouse_hook(win->mlx_win, mouse_click, win);
  exec_ctrl(win);
  mlx_loop(win->mlx);
}
    
