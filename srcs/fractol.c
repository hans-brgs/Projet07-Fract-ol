/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:10:25 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/10 09:52:20 by hbourgeo         ###   ########.fr       */
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
  // printf("\n%p", win->mlx);
  // printf("\n%p", win->mlx);
  // printf("\n%p", win->mlx);
  img = julia_draw (win);
  // mlx_put_image_to_window(win->mlx, win->mlx_win, img->mlx_img, 0, 0);
  // draw_user_interface (win);
  exec_ctrl(win);
  mlx_hook(win->mlx_win, 2, 1L<<0, key_hook, win);
  mlx_mouse_hook(win->mlx_win, mouse_click, win);
  mlx_loop(win->mlx);


    // mlx_loop(mlx);
}
    
