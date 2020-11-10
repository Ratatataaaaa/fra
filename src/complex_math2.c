/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:38:46 by cwing             #+#    #+#             */
/*   Updated: 2020/11/10 19:52:38 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		add_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real + b.real;
	z.imag = a.imag + b.imag;
	return (z);
}

t_complex		sub_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real - b.real;
	z.imag = a.imag - b.imag;
	return (z);
}

double			arg_complex(t_complex z)
{
	if (z.imag == 0 && z.real == 0)
		return (0);
	if (z.real == 0 && z.imag > 0)
		return (0);
	if (z.real == 0 && z.imag < 0)
		return (M_PI);
	if (z.real > 0 && z.imag == 0)
		return (M_PI / 2);
	if (z.real < 0 && z.imag == 0)
		return (-(M_PI / 2));
	if (z.real > 0)
		return (atan(z.imag / z.real));
	if (z.real < 0 && z.imag > 0)
		return (atan(z.imag / z.real) + M_PI);
	if (z.real < 0 && z.imag < 0)
		return (atan(z.imag / z.real) - M_PI);
	return (0);
}

double			mod_complex(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

t_complex		abs_complex(t_complex z)
{
	z.real = fabs(z.real);
	z.imag = fabs(z.imag);
	return (z);
}
