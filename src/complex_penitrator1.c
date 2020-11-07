/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:45:29 by cwing             #+#    #+#             */
/*   Updated: 2020/11/07 17:11:21 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_complex		dev_complex(t_complex a, t_complex b)
{
	t_complex	ret;

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

double			factor(double n)
{
	return (n < 2) ? 1 : n * factor(n - 1);
}

t_complex		pow_complex(t_complex a, int power)
{
	t_complex	ret;
	int			iter;
	double		temp;
	double		ex_c;
	bool		chet[2];

	if (power < 0)
	{
		power = -power;
		a = dev_complex((t_complex){1, 0}, a);
	}
	ret.imag = 0;
	ret.real = pow(a.real, power);
	iter = 0;
	temp = 0;
	chet[0] = true;
	chet[1] = true;
	while (++iter < power)
	{
		ex_c = factor(power) / (factor(power - iter) * factor(power - (power - iter)));
		temp = ex_c * pow(a.real, power - iter) * pow(a.imag, iter);
		if (iter % 2 == 1)
		{
			ret.imag = (chet[1]) ? ret.imag + temp : ret.imag - temp;
			chet[1] = !chet[1];
		}
		else
		{
			ret.real = (chet[0]) ? ret.real - temp : ret.real + temp;
			chet[0] = !chet[0];
		}
	}
	if (power % 2 == 1)
		ret.imag += (chet[1]) ? pow(a.imag, power) : -pow(a.imag, power);
	else
		ret.real += (chet[0]) ? -pow(a.imag, power) : pow(a.imag, power);
	return (ret);
}
