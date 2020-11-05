/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_frctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:48:44 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/05 14:37:28 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void newton_calc(t_cord crd, t_frac *f, t_complex z)
{
	t_pixel color;
	(void)crd;
	(void)f;
	(void)z;
	// t_complex t;
	// // double complex t;
	// double x = (crd.x - X0) * f->pxl;
	// double y = (crd.y - Y0) * f->pxl;
	// complex double z = x + I * y;
	// z.real = x;
	// z.imag = y;
	// if (x || y)
	// {
	// 	t = z;
		
	// 	z = 0.8 * z + 0.2 * cpow(z, -4);

	// 	do
	// 	{
	// 		t = z;
			// z = 0.8 * z + 0.2 * cpow(z, -4);
	// 	} while (cabs(z - t) >= f->eps);

	// 	switch ((int)(carg(z) / f->dpi))
	// 	{
	// 	case 0:
			color = COLOR_RED;
	// 		break;
	// 	case 1:
	// 	case 2:
	// 		color = COLOR_BLACK;
	// 		break;
	// 	case 3:
	// 	case 4:
	// 		color = COLOR_BLUE;
	// 		break;
	// 	case -3:
	// 	case -4:
	// 		color = COLOR_WHITE;
	// 		break;
	// 	case -1:
	// 	case -2:
	// 		color = COLOR_BURLYWOOD;
	// 		break;
	// 	}
		put_pixel(crd.x, crd.y, f, color);
	// }
}

void complex_while(t_frac *f, t_complex z, t_complex c,
				   t_cord crd)
{
	double len_vect;
	register int i;

	f->iter = 0;
	i = 0;
	len_vect = 1;
	if (f->type_fract == NEWTON)
	{
		newton_calc(crd, f, z);
		return ;
	}
	while (f->iter != f->max_iter && len_vect <= 2.3)
	{
		z = addit_complex(multi_complex(z, z), c);
		if (f->type_fract == SHIP)
			z = abs_complex(z);
		len_vect = mod_complex(z);
		f->iter++;
		if (find_color(f, crd) == 1)
			break;
	}
}

void julia_set(t_frac *f, t_cord crd)
{
	t_complex z;
	t_complex c;

	c.real = f->cx;
	c.imag = f->cy;
	z.real = crd.x / f->zoom + f->jx;
	z.imag = crd.y / f->zoom + f->jy;
	complex_while(f, z, c, crd);
}

void other_set(t_frac *f, t_cord crd)
{
	t_complex z;
	t_complex c;

	z.real = f->zx;
	z.imag = f->zy;
	c.real = crd.x / f->zoom + f->cx;
	c.imag = crd.y / f->zoom + f->cy;
	complex_while(f, z, c, crd);
}

void *draw_plur(void *param)
{
	t_frac *f;
	t_cord crd;

	f = (t_frac *)param;
	crd.y = f->cur_y;
	while (crd.y != f->max_y)
	{
		crd.x = 0;
		while (crd.x != WIDTH_WIN - WIDTH_MENU)
		{
			if (f->type_fract == JULIA)
				julia_set(f, crd);
			else
				other_set(f, crd);
			crd.x++;
		}
		crd.y++;
	}
	pthread_exit(0);
}

void pars_frctl(char *av, t_frac *f)
{
	if (ft_strcmp(av, "mand") == 0)
	{
		mand_init(f);
		calc_plur(f);
	}
	else if (ft_strcmp(av, "julia") == 0)
	{
		julia_init(f);
		calc_plur(f);
	}
	else if (ft_strcmp(av, "newton") == 0)
	{
		newton_init(f);
		calc_plur(f);
	}
	else if (ft_strcmp(av, "fire_ship") == 0)
	{
		fire_ship_init(f);
		calc_plur(f);
	}
	else
	{
		error_exit("\033[0;32;1mOh... sorry.\nUse parametr:\033[0m\n\
		[mand]\n\
		[julia]\n\
		[fire_ship]");
	}
}
