/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:31:17 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/10 10:45:23 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIDTH 900
# define HEIGHT 500

typedef struct s_complex
{
	double Re;
	double Im;
}	t_complex;

typedef struct s_fract
{
	int			it_max;
	t_complex	Z0;
	t_complex	Z1;
	t_complex	c;
}	t_fract;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	int			h;
	int			w;
	int			x;
	int			y;
	float		zoom;
	int			It_incr;
	float		moveX;
	float		moveY;
}	t_win;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	int			x;
	int			y;
}	t_img;


// math
double 		sqr(double num);
t_complex 	sqr_cpx(t_complex z);
t_complex	add_cpx(t_complex z, t_complex c);
double 		euclidean_dist(int x1, int x2, int y1, int y2);
double 		slope(int x1, int x2, int y1, int y2);
int 		julia_computation(t_fract *fractol);

// draw
void julia_init (t_fract *fractol);
t_img * julia_draw(t_win *win);
int draw_user_interface (t_win *win);

// color
int color_fractol(t_win *win, t_fract *fractol, int i);
int rgb_to_int(double r, double g, double b);

//init
void win_init(t_win *win);
void img_init(t_win *win, t_img *img, int h, int w);

//utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		mouse_click(int button, int x, int y, t_win *win);
int		key_hook(int keycode, t_win *win);
void 	zoom_in(t_win *win);
void 	moove_left(t_win *win);
void	exec_ctrl(t_win *win);

#ifndef LINUX
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 65351
# define MINUS 65353
#else
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
#endif

#endif
