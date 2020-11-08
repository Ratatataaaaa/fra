/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:45:29 by cwing             #+#    #+#             */
/*   Updated: 2020/11/08 20:19:04 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static double	fac(double n)
{
	return (n < 2) ? 1 : n * fac(n - 1);
}

static void		chet_check(bool *chet, double *ret, double temp, bool znak)
{
	if (znak)
	{
		*ret = (*chet) ? *ret + temp : *ret - temp;
		*chet = !(*chet);
	}
	else
	{
		*ret = (*chet) ? *ret - temp : *ret + temp;
		*chet = !(*chet);
	}
}

static void		init_power(t_complex *ret, int *iter, double *temp, int *power)
{
	(*ret).imag = 0;
	*iter = 0;
	*temp = 0;
	*power = (*power < 0) ? -1 * *power : *power;
}

t_complex		pow_complex(t_complex a, int power)
{
	t_complex	ret;
	int			iter;
	double		temp;
	double		ex_c;
	bool		chet[2];

	a = (power < 0) ? dev_complex((t_complex){1, 0}, a) : a;
	init_power(&ret, &iter, &temp, &power);
	ret.real = pow(a.real, power);
	chet[0] = true;
	chet[1] = true;
	while (++iter < power)
	{
		ex_c = fac(power) / (fac(power - iter) * fac(power - (power - iter)));
		temp = ex_c * pow(a.real, power - iter) * pow(a.imag, iter);
		if (iter % 2 == 1)
			chet_check(&chet[1], &ret.imag, temp, true);
		else
			chet_check(&chet[0], &ret.real, temp, false);
	}
	if (power % 2 == 1)
		ret.imag += (chet[1]) ? pow(a.imag, power) : -pow(a.imag, power);
	else
		ret.real += (chet[0]) ? -pow(a.imag, power) : pow(a.imag, power);
	return (ret);
}
