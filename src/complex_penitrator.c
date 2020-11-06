/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:38:46 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 17:03:26 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		multi_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = (a.real * b.real - a.imag * b.imag);
	z.imag = (a.real * b.imag + a.imag * b.real);
	return (z);
}

t_complex		addit_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real + b.real;
	z.imag = a.imag + b.imag;
	return (z);
}

t_complex		subtraction_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real - b.real;
	z.imag = a.imag - b.imag;
	return (z);
}

double			arg_complex(t_complex z)
{
	double		rez;
	
	if (z.imag == 0 && z. real == 0)
		return (0);
	if (z.real > 0)
		return (atan(z.imag / z.real));
	if (z.real < 0 && z.imag > 0)
		return (atan(atan(z.imag / z.real) + M_PI));
	if (z.real < 0 && z.imag < 0)
		return (atan(atan(z.imag / z.real) - M_PI));
}

double			mod_complex(t_complex z)
{
	double		r;

	r = sqrt(z.real * z.real + z.imag * z.imag);
	return (r);
}

t_complex		abs_complex(t_complex z)
{
	z.real = fabs(z.real);
	z.imag = fabs(z.imag);
	return (z);
}

