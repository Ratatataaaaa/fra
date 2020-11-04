/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:29:15 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 18:14:56 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			switch_plur(t_frac *f)
{
	if (f->type_fract == MAND1)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Mandelbrot");
	else if (f->type_fract == MAND2)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "TriplelBrot");
	else if (f->type_fract == MAND3)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Koridor");
	else if (f->type_fract == MAND4)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Buffalo");
	else if (f->type_fract == MAND5)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Alien");
	else if (f->type_fract == MAND6)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "MegaBrot");
	else if (f->type_fract == MAND7)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Buket");
	switch_plur2(f);
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

	if (f->type_fract == MAND2)
		z2 = multi_complex(multi_complex(z, z), multi_complex(z, z));
	else if (f->type_fract == MAND3)
		z2 = init_mand3(z);
	else if (f->type_fract == MAND4)
		z2 = abs_complex(multi_complex(z, z));
	else if (f->type_fract == MAND5)
		z2 = init_mand5(z);
	else if (f->type_fract == MAND6)
		z2 = quatro_complex(quatro_complex(z, z), quatro_complex(z, z));
	else if (f->type_fract == MAND7)
		z2 = abs_complex(addit_complex(z, quatro_complex(z, z)));
	else
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
