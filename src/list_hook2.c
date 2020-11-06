/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_hook2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:48:13 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:07:56 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		what_init(t_frac *f)
{
	if (f->type_fract == MAND)
		mand_init(f);
	else if (f->type_fract == JULIA)
		julia_init(f);
	else if (f->type_fract == SHIP)
		fire_ship_init(f);
	else if (f->type_fract == NEWTON)
		newton_init(f);
}

int			mouse_move(int x, int y, void *param)
{
	t_frac	*f;

	f = (t_frac *)param;
	f->mouse.prew_x = f->mouse.x;
	f->mouse.prew_y = f->mouse.y;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->mouse.is_pres_key == 1)
	{
		if (f->type_fract == JULIA)
		{
			f->cx -= (x - f->mouse.prew_x) * 0.001;
			f->cy -= (y - f->mouse.prew_y) * 0.001;
		}
		else
		{
			f->zx -= (x - f->mouse.prew_x) * 0.001;
			f->zy -= (y - f->mouse.prew_y) * 0.001;
		}
		calc_plur(f);
	}
	return (0);
}

void		keys0(int key, t_frac *f)
{
	if (key == KEY_ESC)
		close_win(f);
	else if (key == KEY_ENTER)
		open_new_window(f, f->name);
	else if (key == KEY_SPASE)
		spase_swich(f);
	else if (key == KEY_Z || key == KEY_X)
		swap_plur(f, key);
	else if (key == KEY_R || key == KEY_G || key == KEY_B)
		switch_color(f, key);
	else if (key == KEY_T || key == KEY_H || key == KEY_N)
		switch_area(f, key);
	else if (key == KEY_M)
		f->smuze = !f->smuze;
	else if (key == KEY_DELL)
	{
		what_init(f);
		calc_plur(f);
	}

}

void		keys1(int key, t_frac *f)
{
	if (key == KEY_MINUS || key == KEY_PLUS)
	{
		change_color_m(f, key);
		change_color_final(f, key);
		change_color_start(f, key);
		f->colors = cache_colors(f);
		calc_plur(f);

	}
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		switch_color_preset(f, key);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
			key == KEY_RIGHT)
		key_img_move(f, key);
	else if (key == KEY_BRACKETOP || key == KEY_BRACKETCLOSE)
		iter_plus(f, key);
	else if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W)
		key_z_move(f, key);
	else if (key == KEY_Q || key == KEY_E)
		thread_plus(f, key);
}

int			key_press(int key, void *param)
{
	t_frac	*f;

	f = (t_frac *)param;
	keys0(key, f);
	keys1(key, f);
	return (0);
}