/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_hook2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:48:13 by cwing             #+#    #+#             */
/*   Updated: 2020/11/10 19:52:28 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		what_init(t_frac *f)
{
	zero_back(f, 1);
	if (f->type_fract == MAND)
		init_mand(f);
	else if (f->type_fract == JULIA)
		init_juli(f);
	else if (f->type_fract == SHIP)
		init_ship(f);
	else if (f->type_fract == NEWTON)
		init_newt(f);
}

int			mouse_move(int x, int y, void *param)
{
	t_frac	*f;

	f = (t_frac *)param;
	f->mouse.old_x = f->mouse.x;
	f->mouse.old_y = f->mouse.y;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->mouse.is_pres_key == 1)
	{
		if (f->type_fract == JULIA)
		{
			f->cx -= (x - f->mouse.old_x) * 0.001;
			f->cy -= (y - f->mouse.old_y) * 0.001;
		}
		else
		{
			f->zx -= (x - f->mouse.old_x) * 0.001;
			f->zy -= (y - f->mouse.old_y) * 0.001;
		}
		calc_plur(f);
	}
	return (0);
}

void		keys0(int key, t_frac *f)
{
	if (key == KEY_ESC || key == 65307)
		close_win(f);
	else if (key == KEY_ENTER)
		open_win(f, f->name);
	else if (key == KEY_SPASE || key == 32)
		spase_swich(f);
	else if (key == KEY_Z || key == KEY_X)
		swap_plur(f, key);
	else if (key == KEY_R || key == KEY_G || key == KEY_B)
		switch_color(f, key);
	else if (key == KEY_T || key == KEY_H || key == KEY_N)
		switch_area(f, key);
	else if (key == KEY_M)
	{
		f->smuze = !f->smuze;
		calc_plur(f);
	}
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
		ch_menu_color(f, key);
		ch_final_color(f, key);
		ch_start_color(f, key);
		calc_plur(f);
	}
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		switch_color_preset(f, key);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
			key == KEY_RIGHT)
		key_img_move(f, key);
	else if (key == KEY_BRACKETOP || key == KEY_BRACKETCLOSE || key == 93 || key == 91)
		iter_plus(f, key);
	else if (key == 119 || key == 115 || key == 100 || key == 97)
		key_z_move(f, key);
	else if (key == KEY_Q || key == KEY_E)
		thread_plus(f, key);
}

int			key_press(int key, void *param)
{
	keys0(key, (t_frac *)param);
	keys1(key, (t_frac *)param);
	return (0);
}
