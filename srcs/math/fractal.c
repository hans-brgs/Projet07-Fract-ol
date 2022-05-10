/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:28:36 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/05/09 19:28:36 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_computation(t_win *win)
{
	int i;
	
	i = 0;
	while (i < win->julia->it_max + win->It_incr)
	{
		win->julia->Z0 = win->julia->Z1;
		win->julia->Z1 = add_cpx(sqr_cpx(win->julia->Z0), win->julia->c);
		if ((sqr(win->julia->Z1.Re) + sqr(win->julia->Z1.Im)) > 4)
		{
			break;
		}
		i++;
	}
	return (i);
}