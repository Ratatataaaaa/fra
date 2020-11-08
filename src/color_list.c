/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:15:49 by cwing             #+#    #+#             */
/*   Updated: 2020/11/08 18:29:24 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ch_start_color(t_frac *f, int key)
{
	if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key == KEY_PLUS)
		f->color.start.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.blue -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.green -= 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.red -= 5;
}

void	ch_menu_color(t_frac *f, int key)
{
	if ((f->clr_sw.blue == 1) && (f->clr_sw.plural == 1) && key == KEY_PLUS)
		f->color.plural.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.plural == 1) && key ==
		KEY_MINUS)
		f->color.plural.blue -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plural == 1) && key ==
		KEY_PLUS)
		f->color.plural.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plural == 1) && key ==
		KEY_MINUS)
		f->color.plural.green -= 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.plural == 1) && key ==
		KEY_PLUS)
		f->color.plural.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.plural == 1) && key ==
		KEY_MINUS)
		f->color.plural.red -= 5;
}

void	ch_final_color(t_frac *f, int key)
{
	if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key == KEY_PLUS)
		f->color.final.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.blue -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.green -= 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.red -= 5;
}

void	switch_color(t_frac *f, int key)
{
	if (key == KEY_R)
		f->clr_sw.blue *= -1;
	else if (key == KEY_G)
		f->clr_sw.green *= -1;
	else if (key == KEY_B)
		f->clr_sw.red *= -1;
	put_menu(f);
}

void	switch_area(t_frac *f, int key)
{
	if (key == KEY_T)
		f->clr_sw.start *= -1;
	else if (key == KEY_H)
		f->clr_sw.plural *= -1;
	else if (key == KEY_N)
		f->clr_sw.final *= -1;
	put_menu(f);
}
