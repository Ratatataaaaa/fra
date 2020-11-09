/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:56:30 by cwing             #+#    #+#             */
/*   Updated: 2020/11/09 07:09:45 by kain2250         ###   ########.fr       */
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
		[newton]\n\
		[ship]");
	}
	calc_plur(f);
}

void		error_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

void		cache_colors2(int bufer_iter, bool vec, t_frac *f)
{
	int		iter;
	int		iter_j = f->dev_iter;

	if (bufer_iter > f->max_iter)
		return ;
	iter = 0;
	while (iter <= f->dev_iter)
	{
		if (vec)
		{
			f->colors[bufer_iter] = get_color(iter, f->color.start, f->color.final, f, true);
		}
		else
		{
			f->colors[bufer_iter] = get_color(iter_j, f->color.start, f->color.final, f, true);
		}
		++bufer_iter;
		++iter;
		--iter_j;
	}
	f->dev_iter = f->dev_iter / 2;
	cache_colors2 (bufer_iter, !vec, f);
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
		// int	temp = f->max_iter / 2;
		// int reset = temp;
		// int reset2 = f->max_iter;

		
		cache_colors2 (0, true, f);
		
	}
	f->colors_size = f->max_iter;
	return (f->colors);
}

// {
// 	int		i;

// 	i = 0;
// 	if (f->colors == NULL)
// 		f->colors = (t_pixel *)malloc(sizeof(t_pixel) * f->max_iter);
// 	if (f->colors_size != f->max_iter)
// 	{
// 		free(f->colors);
// 		f->colors = (t_pixel *)malloc(sizeof(t_pixel) * f->max_iter);
// 	}
// 	if (f->colors)
// 	{
// 		int	temp = f->max_iter / 2;
// 		int reset = temp;
// 		int reset2 = f->max_iter;

// 		while (i < f->max_iter)
// 		{
// 			if (i < temp)
// 				f->colors[i] = get_color(i, f->color.start, f->color.final, f, 1);
// 			else if (i > temp && i < temp + temp / 2)
// 				f->colors[i] = get_color(i, f->color.start, f->color.final, f, 2);
// 			else
// 				f->colors[i] = get_color(i, f->color.start, f->color.final, f, 3);
// 			++i;
// 		}
// 	}
// 	f->colors_size = f->max_iter;
// 	return (f->colors);
// }

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
		[newton]\n\
		[ship]");
	return (0);
}
