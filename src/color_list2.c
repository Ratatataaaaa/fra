/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:12:26 by cwing             #+#    #+#             */
/*   Updated: 2020/12/01 13:54:56 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		switch_color_preset(t_frac *f, int key)
{
	if (key == KEY_1)
	{
		f->color.odd = 0;
		f->color.inter = 1;
	}
	else if (key == KEY_2)
	{
		f->color.odd = 1;
		f->color.inter = 0;
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

void		odd_pars(t_frac *f, t_cord crd)
{
	t_pixel	temp;

	if (f->iter % 2 == 1)
		put_pixel(crd.x, crd.y, f, f->colors[f->iter]);
	else
	{
		temp = (t_pixel){255, 255, 255, 1};
		put_pixel(crd.x, crd.y, f, temp);
	}
}

void		interpol_pars(t_frac *f, t_cord crd)
{
	put_pixel(crd.x, crd.y, f, f->colors[f->iter]);
}

int			find_color(t_frac *f, t_cord crd)
{
	if (f->iter == f->max_iter)
	{
		put_pixel(crd.x, crd.y, f, COLOR_BLACK);
		return (1);
	}
	else
	{
		if (f->color.odd == 1)
			odd_pars(f, crd);
		else if (f->color.inter == 1)
			interpol_pars(f, crd);
	}
	return (0);
}
