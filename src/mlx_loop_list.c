/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:28:46 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:07:39 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_img_move(t_frac *f, int key)
{
	if (f->type_fract == JULIA)
	{
		if (key == KEY_DOWN)
			f->jy -= f->range_move;
		else if (key == KEY_UP)
			f->jy += f->range_move;
		else if (key == KEY_RIGHT)
			f->jx -= f->range_move;
		else
			f->jx += f->range_move;
	}
	else
	{
		if (key == KEY_DOWN)
			f->cy -= f->range_move;
		else if (key == KEY_UP)
			f->cy += f->range_move;
		else if (key == KEY_RIGHT)
			f->cx -= f->range_move;
		else
			f->cx += f->range_move;
	}
	calc_plur(f);
}

void		iter_plus(t_frac *f, int key)
{
	if (key == KEY_BRACKETCLOSE)
		f->max_iter += 10;
	else
		f->max_iter -= 10;
	if (f->max_iter < 10)
		f->max_iter = 10;
	if (f->max_iter > INT_MAX)
		f->max_iter = INT_MAX;
	f->colors = cache_colors(f);
	calc_plur(f);
}

void		swap_plur(t_frac *f, int key)
{
	if ((key == KEY_Z) && (f->type_fract != 1))
	{
		f->type_fract -= 1;
		what_init(f);
	}
	else if ((key == KEY_X) && (f->type_fract != 4))
	{
		f->type_fract += 1;
		what_init(f);
	}
	calc_plur(f);
}

void		key_z_move(t_frac *f, int key)
{
	if (f->type_fract != JULIA)
	{
		if (key == KEY_S)
			f->zy -= f->range_move;
		else if (key == KEY_W)
			f->zy += f->range_move;
		else if (key == KEY_D)
			f->zx -= f->range_move;
		else
			f->zx += f->range_move;
	}
	else
	{
		if (key == KEY_S)
			f->cy -= f->range_move;
		else if (key == KEY_W)
			f->cy += f->range_move;
		else if (key == KEY_D)
			f->cx -= f->range_move;
		else
			f->cx += f->range_move;
	}
	calc_plur(f);
}

void		mlx_loop_list(t_frac *f)
{
	mlx_hook(f->win, 2, (1L << 1), key_press, f);
	mlx_hook(f->win, 17, 1, cls, f);
	mlx_hook(f->win, 4, (1L << 2), mouse_key, f);
	mlx_hook(f->win, 6, (1L << 13), mouse_move, f);
	mlx_loop(f->ptr);
}
