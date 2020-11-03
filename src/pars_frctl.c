/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_frctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:48:44 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/03 21:02:17 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				complex_while(t_frctl *f, t_complex z, t_complex c,
					t_crd crd)
{
	double			len_vect;
	t_complex		z2;
	register int	i;

	f->iter = 0;
	i = 0;
	len_vect = 1;
	while (f->iter != f->max_iter && len_vect <= 2.3)
	{
		if (f->type_fract == NEWTON)
		{
			z2 = subtraction_complex(z, subtraction_complex(pow_complex(z, 3), (t_complex){1, 0}));
			t_complex z3 = multi_complex(pow_complex(z, 2), (t_complex){3, 0});
			z = devision_complex(z2, z3);
		}
		else
		{
			z2 = multi_complex(z, z);
			if (f->type_fract > MAND1 && f->type_fract < JULIA)
				z2 = mand_who(f, z);
			z = addit_complex(z2, c);
			if (f->type_fract == SHIP)
				z = abs_complex(z);
		}
		len_vect = mod_complex(z);
		f->iter++;
		if (find_color(f, crd) == 1)
			break ;
	}
}

void				julia_set(t_frctl *f, t_crd crd)
{
	t_complex		z;
	t_complex		c;

	c.real = f->cx;
	c.imag = f->cy;
	z.real = crd.x / f->zoom + f->jx;
	z.imag = crd.y / f->zoom + f->jy;
	complex_while(f, z, c, crd);
}

void				other_set(t_frctl *f, t_crd crd)
{
	t_complex		z;
	t_complex		c;

	z.real = f->zx;
	z.imag = f->zy;
	c.real = crd.x / f->zoom + f->cx;
	c.imag = crd.y / f->zoom + f->cy;
	complex_while(f, z, c, crd);
}

void				*draw_plur(void *param)
{
	t_frctl			*f;
	t_crd			crd;

	f = (t_frctl *)param;
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

void				pars_frctl(char *av, t_frctl *f)
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
