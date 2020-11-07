/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:56:30 by cwing             #+#    #+#             */
/*   Updated: 2020/11/07 17:21:38 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pars_frctl(char *av, t_frac *f)
{
	if (ft_strcmp(av, "mand") == 0)
		init_mand(f);
	else if (ft_strcmp(av, "julia") == 0)
		init_juli(f);
	else if (ft_strcmp(av, "newton") == 0)
		init_newt(f);
	else if (ft_strcmp(av, "ship") == 0)
		init_ship(f);
	else
	{
		error_exit("\033[0;32;1mOh... sorry.\nUse parametr:\033[0m\n\
		[mand]\n\
		[julia]\n\
		[ship]");
	}
	calc_plur(f);
}

void		error_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

t_pixel		*cache_colors(t_frac *f)
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
	t_frac	*f;

	if (ac == 2)
	{
		if (!(f = (t_frac *)ft_memalloc(sizeof(t_frac))))
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
		[ship]");
	return (0);
}
