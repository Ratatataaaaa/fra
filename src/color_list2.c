/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:12:26 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 20:30:26 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_color_preset(t_frac *f, int key)
{
	if (key == KEY_1)
	{
		f->color.odd = 0;
		f->color.interpol = 1;
	}
	else if (key == KEY_2)
	{
		f->color.odd = 1;
		f->color.interpol = 0;
	}
	else if (key == KEY_3)
		f->dpi += 1;
	else if (key == KEY_4)
	{
		f->dpi -= 1;
		if (f->dpi <= 1)
			f->dpi = 2;
	}
	calc_plur(f);
}

void	odd_pars(t_frac *f, t_cord crd)
{
	t_pixel	temp;

	if (f->iter % 2 == 1)
		put_pixel(crd.x, crd.y, f, f->colors[f->iter]);
	else
	{
		// f->color.final = COLOR_BURLYWOOD;
		// f->color.start = COLOR_BLACK;
		// f->colors = cache_colors(f);
		temp = (t_pixel){255, 255, 255, 0};
		put_pixel(crd.x, crd.y, f, temp);//f->colors[f->iter]);
		// f->color.start = COLOR_BLACK;
		// f->color.final = COLOR_BLUE;
		// f->colors = cache_colors(f);
	}
}

void	interpol_pars(t_frac *f, t_cord crd)
{
	put_pixel(crd.x, crd.y, f, f->colors[f->iter]);
}

int		find_color(t_frac *f, t_cord crd)
{
	if (f->iter == f->max_iter)
	{
		put_pixel(crd.x, crd.y, f, f->color.plur);
		return (1);
	}
	else
	{
		if (f->color.odd == 1)
			odd_pars(f, crd);
		else if (f->color.interpol == 1)
			interpol_pars(f, crd);
	}
	return (0);
}
