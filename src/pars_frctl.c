/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_frctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:48:44 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 21:54:16 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void newton_calc(t_cord crd, t_frac *f, t_complex c)
{
	t_pixel		color;
	t_complex 	t;
	int			arg;
	int			i;

	if (c.real && c.imag)
	{
		t = c;
		c = addit_complex(multi_complex((t_complex){0.8, 0}, c),
			multi_complex((t_complex){0.2, 0}, pow_complex(c, -4)));
		i = 0;
		while (mod_complex(subtraction_complex(c, t)) >= f->eps && i < f->max_iter)
		{
			t = c;
			c = addit_complex(multi_complex((t_complex){0.8, 0}, c),
				multi_complex((t_complex){0.2, 0}, pow_complex(c, -4)));
			i++;
		}
		// arg = (int)(arg_complex(c) / f->dpi);
		// if (arg == 0)
		// 	color = AQUAMARINEE;
		// else if (arg == 1 || arg == 2)
		// 	color = TURQOISE;
		// else if (arg == 3 || arg == 4)
		// 	color = DARK_TURQOISE;
		// else if (arg == -3 || arg == -4)
		// 	color = DEEP_SKY_BLUE;
		// else if (arg == -1 || arg == -2)
		// 	color = CYAN;
		// else
		// 	color = COLOR_RED;
		put_pixel(crd.x, crd.y, f, f->colors[i]);
	}
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
		newton_calc(crd, f, c);
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
	c.real = (f->type_fract == NEWTON) ? (crd.x - X0) / f->zoom + f->cx : crd.x / f->zoom + f->cx;
	c.imag = (f->type_fract == NEWTON) ? (crd.y - Y0) / f->zoom + f->cy : crd.y / f->zoom + f->cy;
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
