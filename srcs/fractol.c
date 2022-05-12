/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:10:25 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/13 00:12:42 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	arg_handler(char *str)
{
	if (ft_strncmp(str, "Julia1", 7) == 0)
		return (1);
	else if (ft_strncmp(str, "Julia2", 7) == 0)
		return (2);
	else if (ft_strncmp(str, "Mandelbrot", 11) == 0)
		return (3);
	else if (ft_strncmp(str, "Burningship", 12) == 0)
		return (4);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_win	*win;

	if (argc != 2 || arg_handler(argv[1]) == 0)
	{
		ft_printf("Enter the appropriate name of the fractal as argument:");
		ft_printf("\n(1) Julia1");
		ft_printf("\n(2) Julia2");
		ft_printf("\n(3) Mandelbrot");
		ft_printf("\n(4) Burningship");
		return (0);
	}
	win = malloc(sizeof(t_win));
	if (!win)
		return (-1);
	win_init(win);
	win->select = arg_handler(argv[1]);
	mlx_hook(win->ptr, 3, 1L << 1, key_hook, win);
	mlx_mouse_hook(win->ptr, mouse_click, win);
	mlx_hook(win->ptr, 17, 1L << 17, close_and_free, win);
	render(win);
	mlx_loop(win->mlx);
	return (0);
}
