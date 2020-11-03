/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:01:57 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/15 23:09:41 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		thread_plus(t_frctl *f, int key)
{
	if (key == KEY_E)
		f->threads += 1;
	else
		f->threads -= 1;
	if (f->threads < 2)
		f->threads = 2;
	if (f->threads > INT_MAX)
		f->threads = INT_MAX;
	put_menu(f);
}

void		spase_swich(t_frctl *f)
{
	if (f->mouse.is_pres_key == 1)
		f->mouse.is_pres_key = 0;
	else
		f->mouse.is_pres_key = 1;
	put_menu(f);
}

void		open_new_window(t_frctl *f, char *av)
{
	if (f->count_window == 0)
	{
		f->new_win[f->count_window] = (t_frctl *)ft_memalloc(sizeof(t_frctl));
		f->new_win[f->count_window]->count_window = f->count_window + 1;
		init_mlx(f->new_win[f->count_window], av);
		pars_frctl(av, f->new_win[f->count_window]);
		mlx_loop_list(f->new_win[f->count_window]);
	}
}

void		close_win(t_frctl *f)
{
	if (f->count_window == 0)
		exit(0);
	else
	{
		mlx_clear_window(f->ptr, f->win);
		mlx_destroy_image(f->ptr, f->img);
		mlx_destroy_window(f->ptr, f->win);
		f->count_window -= 1;
	}
}

int			cls(void *param)
{
	t_frctl	*f;

	f = (t_frctl *)param;
	close_win(f);
	return (0);
}
