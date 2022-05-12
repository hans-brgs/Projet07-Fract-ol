/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:31:17 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/12 23:58:52 by hbourgeo         ###   ########.fr       */
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
# define W 800
# define H 600

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_fract
{
	int			it_max;
	t_complex	z0;
	t_complex	z1;
	t_complex	c;
}	t_fract;

typedef struct s_koch
{
	t_coord	a;
	t_coord	b;
	t_coord	c;
	t_coord	d;
	t_coord	e;
}	t_koch;

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

typedef struct s_win
{
	void		*mlx;
	void		*ptr;
	int			h;
	int			w;
	int			x;
	int			y;
	float		zoom;
	int			it_incr;
	float		move_x;
	float		move_y;
	int			select;
	int			mutate_julia;
	int			color;
	double		julia_c_re;
	double		julia_c_im;
	t_fract		*curr_fract;
	t_img		*img;
	t_img		*ui1;
	t_img		*ui2;
	t_img		*ui3;
}	t_win;

// math
double		sqr(double num);
t_complex	sqr_cpx(t_complex z);
t_complex	add_cpx(t_complex z, t_complex c);
t_complex	sqr_cpx_abs(t_complex z);
int			julia_computation(t_win *win, t_complex cplx);
int			mandelbrot_computation(t_win *win, t_complex cplx);
int			burningship_computation(t_win *win, t_complex cplx);

// draw
void		draw_fractal(t_win *win);
int			draw_user_interface(t_win *win);

// color
int			color_fractal(t_win *win, int i);
int			rgb_to_int(double r, double g, double b);

//init
void		img_init(t_win *win, t_img *img, int h, int w);
void		win_init(t_win *win);
void		julia_init(t_win *win);
void		mandelbrot_init(t_win *win);

//utils
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			mouse_click(int button, int x, int y, t_win *win);
int			key_hook(int keycode, t_win *win);
void		render(t_win *win);
void		reset_fractal(t_win *win);
int			close_and_free(t_win *win);
void		julia_transform(t_win *win);
void		set_julia(t_win *win, double cRe, double cIm);

//error
void		exit_error(t_win *win, char *str);
void		free_str(t_win *win);

# ifdef __APPLE__
#  define K_CLOSE 53
# endif
# ifdef __linux__
#  define K_CLOSE 65307
# endif

# ifdef __linux__
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define PLUS 65451
#  define MINUS 65453
#  define NUMPAD_1 65436
#  define NUMPAD_2 65433
#  define NUMPAD_3 65435
#  define CLEAR 65535
#  define ESCAPE 65307
#  define MUTATE 106
#  define COLOR 99
# endif
# ifdef __APPLE__
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define PLUS 24
#  define MINUS 27
#  define NUMPAD_1 83
#  define NUMPAD_2 84
#  define NUMPAD_3 85
#  define CLEAR 71
#  define ESCAPE 53
#  define MUTATE 106
#  define COLOR 38
# endif

#endif
