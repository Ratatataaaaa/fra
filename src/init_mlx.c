/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:27:49 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/03 23:49:25 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mand_init(t_frctl *ptr)
{
	ptr->zoom = 300.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom - 0.5;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom ;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->max_iter = 50;
	ptr->start_iter = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_BLACK;
	ptr->color.final = COLOR_BLUE;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		fire_ship_init(t_frctl *ptr)
{
	ptr->type_fract = SHIP;
	ptr->zoom = 310.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->cur_y = 0;
	ptr->max_iter = 50;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->start_iter = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_BLACK;
	ptr->color.final = COLOR_BLUE;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		newton_init(t_frctl *ptr)
{
	ptr->type_fract = NEWTON;
	ptr->zoom = 320.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->start_iter = 0;
	ptr->max_iter = 40;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_BLACK;
	ptr->color.final = COLOR_BLUE;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		julia_init(t_frctl *ptr)
{
	ptr->type_fract = JULIA;
	ptr->zoom = 320.00;
	ptr->cx = -0.63;
	ptr->cy = -0.54;
	ptr->jx = -1.6;
	ptr->jy = -1.2;
	ptr->start_iter = 0;
	ptr->max_iter = 40;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_BLACK;
	ptr->color.final = COLOR_BLUE;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		put_menu_color_type(t_frctl *f)
{
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'+/=' - Color + ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'-' - Color - ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Ti pidor)");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'2' - Set_Color_2");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'Z' - Plur - ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'X' - Plur + ");
}

void		init_mlx(t_frctl *ptr, char *av)
{
	if (!(ptr->ptr = mlx_init()))
		error_exit("\033[0;31;1mError mlx_init\033[0m");
	if (!(ptr->win = mlx_new_window(ptr->ptr, WIDTH_WIN, HEIGHT_WIN, av)))
		error_exit("\033[0;31;1mError win_init\033[0m");
	if (!(ptr->img = mlx_new_image(ptr->ptr, WIDTH_WIN - WIDTH_MENU,
		HEIGHT_WIN)))
		error_exit("\033[0;31;1mError img_init\033[0m");
	if (!(ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bits_per_pixel),
		&(ptr->size_line), &(ptr->endian))))
		error_exit("\033[0;31;1mError img_init\033[0m");
	if (!(ptr->menu.img = mlx_new_image(ptr->ptr, WIDTH_MENU, HEIGHT_MENU)))
		error_exit("\033[0;31;1mError img_init\033[0m");
	ptr->menu.data_addr = mlx_get_data_addr(ptr->menu.img,
	&(ptr->menu.bits_per_pixel), &(ptr->menu.size_line), &(ptr->menu.endian));
	ptr->color.interpol = 1;
	ptr->range_move = 0.01;
	ptr->max_iter = 50;
	ptr->threads = 16;
	ptr->clr_sw.red = -1;
	ptr->clr_sw.blue = -1;
	ptr->clr_sw.green = -1;
	ptr->clr_sw.start = -1;
	ptr->clr_sw.plur = -1;
	ptr->clr_sw.final = -1;
	ptr->type_fract = MAND1;
}
