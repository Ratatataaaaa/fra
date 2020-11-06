/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:45:29 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:08:14 by cwing            ###   ########.fr       */
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

double		factor(double n)
{
	return (n < 2) ? 1 : n * factor (n - 1);
}

t_complex		pow_complex(t_complex a, int power)
{
	t_complex	ret;
	int			iter;
	double		temp;
	double		ex_c;
	bool		chet_r;
	bool		chet_i;
	bool		true_pow;

	if (power < 0)
	{
		power = -power;
		true_pow = true;
	}
	else
		true_pow = false; 
	ret.imag = 0;
	ret.real = pow(a.real, power);
	//ret.imag = (power % 2 == 1) ?  -1 * pow(a.imag, power) : pow(a.imag, power);
	iter = 0;
	temp = 0;
	chet_r = true;
	chet_i = true;
	while (++iter < power)
	{
		ex_c = factor(power) / (factor(power - iter) * factor(power - (power - iter)));
		printf("ex_c = %f\n", ex_c);
		temp = ex_c * pow(a.real, power - iter) * pow(a.imag, iter);
		printf("temp = %f\n", temp);
		if (iter % 2 == 1)
		{
			if (chet_i)
				ret.imag += temp;
			else
				ret.imag -= temp;
			chet_i = !chet_i;
		}
		else
		{
			if (chet_r)
				ret.real -= temp;
			else
				ret.real += temp;
			chet_r = !chet_r;
		}
			// ret.real -=temp;
	}
	if (power % 2 == 1)
		ret.imag += (chet_i) ? pow(a.imag, power) : -pow(a.imag, power);
	else
		ret.real += (chet_r) ? -pow(a.imag, power) : pow(a.imag, power);
	if (true_pow)
		ret = devision_complex((t_complex){1, 0}, ret);
	printf("real = %f  imag = %f\n", ret.real, ret.imag);
	return (ret);
}
