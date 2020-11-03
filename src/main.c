/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:56:30 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 00:15:56 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		switch_plur2(t_frctl *f)
{
	if (f->type_fract == MAND8)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "SeaBrot");
	else if (f->type_fract == JULIA)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Julia");
	else if (f->type_fract == SHIP)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		0xffffff, "Fire_Ship");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	0x00ff00, "--------------------");
}

void		error_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

t_pixel		*cache_colors(t_frctl *f)
{
	int		i;

	i = 0;
	if (f->colors == NULL)
		f->colors = (t_pixel *)malloc(sizeof(t_pixel) * f->max_iter);
	if (f->colors_size != f->max_iter)
	{
		free(f->colors);
		f->colors = (t_pixel *)malloc(sizeof(t_pixel) * f->max_iter);
	}
	if (f->colors)
	{
		while (i < f->max_iter)
		{
			f->colors[i] = get_color(i, f->color.start, f->color.final, f);
			++i;
		}
	}
	f->colors_size = f->max_iter;
	return (f->colors);
}

int			main(int ac, char **av)
{
	t_frctl	*f;

	if (ac == 2)
	{
		if (!(f = (t_frctl *)ft_memalloc(sizeof(t_frctl))))
			error_exit("\033[0;31;1mError malloc by [s_frctl]\033[0m");
		f->count_window = 0;
		init_mlx(f, (f->name = av[1]));
		pars_frctl(f->name, f);
		mlx_loop_list(f);
	}
	else
		error_exit("\033[0;32;1mOh... sorry.\nUse parametr:\033[0m\n\
		[mand]\n\
		[julia]\n\
		[fire_ship]");
	return (0);
}
