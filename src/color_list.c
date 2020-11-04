/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:49 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 17:53:49 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_start(t_frac *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key == KEY_PLUS)
		f->color.start.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.red -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.green -= 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start.blue -= 5;
}

void	change_color_m(t_frac *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.plur == 1) && key == KEY_PLUS)
		f->color.plur.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur.red -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_PLUS)
		f->color.plur.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur.green -= 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_PLUS)
		f->color.plur.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur.blue -= 5;
}

void	change_color_final(t_frac *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key == KEY_PLUS)
		f->color.final.red += 5;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.red -= 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final.green += 5;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.green -= 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final.blue += 5;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final.blue -= 5;
}

void	switch_color(t_frac *f, int key)
{
	if (key == KEY_R)
		f->clr_sw.red *= -1;
	else if (key == KEY_G)
		f->clr_sw.green *= -1;
	else if (key == KEY_B)
		f->clr_sw.blue *= -1;
	put_menu(f);
}

void	switch_area(t_frac *f, int key)
{
	if (key == KEY_T)
		f->clr_sw.start *= -1;
	else if (key == KEY_H)
		f->clr_sw.plur *= -1;
	else if (key == KEY_N)
		f->clr_sw.final *= -1;
	put_menu(f);
}
