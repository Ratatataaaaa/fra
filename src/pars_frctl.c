/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_frctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:48:44 by cwing             #+#    #+#             */
/*   Updated: 2020/11/10 19:52:28 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				newton_calc(t_cord crd, t_frac *f, t_complex c)
{
	t_complex		t;
	int				i;

	if (c.real && c.imag)
	{
		t = c;
		c = add_complex(mlt_complex((t_complex){0.8, 0}, c),
			mlt_complex((t_complex){0.2, 0}, pow_complex(c, -4)));
		i = 0;
		while (mod_complex(sub_complex(c, t)) >= f->eps && i < f->max_iter)
		{
			t = c;
			c = add_complex(mlt_complex((t_complex){0.8, 0}, c),
				mlt_complex((t_complex){0.2, 0}, pow_complex(c, -4)));
			i++;
		}
		if (i == 0)
			put_pixel(crd.x, crd.y, f, COLOR_BLACK);
		else
			put_pixel(crd.x, crd.y, f, f->colors[i - 1]);
	}
}

void				complex_while(t_frac *f, t_complex z, t_complex c,
					t_cord crd)
{
	double			len_vect;

	f->iter = 0;
	len_vect = 1;
	if (f->type_fract == NEWTON)
	{
		newton_calc(crd, f, c);
		return ;
	}
	while (f->iter != f->max_iter && len_vect <= 2.3)
	{
		z = add_complex(mlt_complex(z, z), c);
		if (f->type_fract == SHIP)
			z = abs_complex(z);
		len_vect = mod_complex(z);
		f->iter++;
		if (find_color(f, crd) == 1)
			break ;
	}
}

void				julia_set(t_frac *f, t_cord crd)
{
	t_complex		z;
	t_complex		c;

	c.real = f->cx;
	c.imag = f->cy;
	z.real = crd.x / f->zoom + f->jx;
	z.imag = crd.y / f->zoom + f->jy;
	complex_while(f, z, c, crd);
}

void				other_set(t_frac *f, t_cord crd)
{
	t_complex		z;
	t_complex		c;

	z.real = f->zx;
	z.imag = f->zy;
	c.real = (f->type_fract == NEWTON) ?
	(crd.x - X0) / f->zoom + f->cx : crd.x / f->zoom + f->cx;
	c.imag = (f->type_fract == NEWTON) ?
	(crd.y - Y0) / f->zoom + f->cy : crd.y / f->zoom + f->cy;
	complex_while(f, z, c, crd);
}

void				*draw_plur(void *param)
{
	t_frac			*f;
	t_cord			crd;

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
