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

int julia_computation(t_fract *fractol)
{
	int i;
	
	i = 0;
	while (i < fractol->it_max)
	{
		fractol->Z0 = fractol->Z1;
		fractol->Z1 = add_cpx(sqr_cpx(fractol->Z0), fractol->c);
		if ((fractol->Z1.Re * fractol->Z1.Re + fractol->Z1.Im * fractol->Z1.Im) > 4)
		{
			break;
		}
		i++;
	}
	return (i);
}