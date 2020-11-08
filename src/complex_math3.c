/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:52:39 by cwing             #+#    #+#             */
/*   Updated: 2020/11/08 20:17:00 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		mlt_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = (a.real * b.real - a.imag * b.imag);
	z.imag = (a.real * b.imag + a.imag * b.real);
	return (z);
}

t_complex		sct_complex(t_complex z, char *real, char *imag)
{
	if (ft_strcmp(real, "sin") == 0)
		z.real = sin(z.real);
	if (ft_strcmp(imag, "sin") == 0)
		z.imag = sin(z.imag);
	if (ft_strcmp(real, "cos") == 0)
		z.real = cos(z.real);
	if (ft_strcmp(imag, "cos") == 0)
		z.imag = cos(z.imag);
	if (ft_strcmp(real, "tan") == 0)
		z.real = tan(z.real);
	if (ft_strcmp(imag, "tan") == 0)
		z.imag = tan(z.imag);
	return (z);
}

t_complex		qtr_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z = mlt_complex(mlt_complex(a, b), mlt_complex(a, b));
	return (z);
}
