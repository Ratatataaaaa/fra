/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:45:29 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/03 21:18:52 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		sin_cos_tg_complex(t_complex z, char *real, char *imag)
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

t_complex		quatro_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z = multi_complex(multi_complex(a, b), multi_complex(a, b));
	return (z);
}

t_complex		devision_complex(t_complex a, t_complex b)
{
	t_complex ret;

	ret.real = (a.real * b.real + a.imag * b.imag) /
		(b.real * b.real + b.imag * b.imag);
	if (ret.real != ret.real)
		ret.real = 0.;
	ret.imag = (b.real * a.imag - a.real * b.imag) /
		(b.real * b.real + b.imag * b.imag);
	if (ret.imag != ret.imag)
		ret.imag = 0.;

	return (ret);
}

t_complex		pow_complex(t_complex a, int power)
{
	t_complex	temp;

	while (power != 0)
	{
		temp = multi_complex(a, a);
		--power;
	}
	return (temp);
}
