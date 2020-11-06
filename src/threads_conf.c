/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:29:15 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:07:13 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			switch_plur(t_frac *f)
{
	if (f->type_fract == MAND)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Mandelbrot");
	else if (f->type_fract == JULIA)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Julia");
	else if (f->type_fract == SHIP)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Fire_Ship");
	else if (f->type_fract == NEWTON)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Newton pool");
}

t_complex		init_mand3(t_complex z)
{
	t_complex	z2;

	z2 = sin_cos_tg_complex(z, "tan", "tan");
	return (z2);
}

t_complex		init_mand5(t_complex z)
{
	t_complex	z2;
	t_complex	z3;

	z3.real = mod_complex(z);
	z3.imag = mod_complex(z);
	z2 = multi_complex(z3, z3);
	return (z2);
}

t_complex		mand_who(t_frac *f, t_complex z)
{
	t_complex	z2;

	(void)f;
	z2 = sin_cos_tg_complex(quatro_complex(z, z), "tan", "sin");
	return (z2);
}

void			calc_plur(t_frac *f)
{
	pthread_t	tid[f->threads];
	t_frac		cur[f->threads];
	int			i;
	double		w_w;

	i = -1;
	w_w = WIDTH_WIN - WIDTH_MENU;
	while (++i < f->threads)
	{
		ft_memcpy((void *)&cur[i], (void *)f, sizeof(t_frac));
		cur[i].cur_y = ((1.00 / f->threads) * w_w) * (i);
		cur[i].max_y = ((1.00 / f->threads) * w_w) * (i + 1);
	}
	i = 0;
	while (i < f->threads)
	{
		pthread_create(&tid[i], NULL, draw_plur, &cur[i]);
		++i;
	}
	i = 0;
	while (i < f->threads)
		pthread_join(tid[i++], NULL);
	mlx_put_image_to_window(f->ptr, f->win, f->img, 0, 0);
	put_menu(f);
}
