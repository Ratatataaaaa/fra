/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:27:49 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 17:03:20 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mand_init(t_frac *ptr)
{
	ptr->type_fract = MAND;
	ptr->zoom = 150.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom - 0.5;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom ;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->max_iter = 50;
	ptr->start_iter = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_YELLOW;
	ptr->color.final = COLOR_BLUE;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		fire_ship_init(t_frac *ptr)
{
	ptr->type_fract = SHIP;
	ptr->zoom = 150.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->cur_y = 0;
	ptr->max_iter = 50;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->start_iter = 0;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_DARKTURQUIOSE;
	ptr->color.final = COLOR_GOLD;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		newton_init(t_frac *ptr)
{
	ptr->type_fract = NEWTON;
	ptr->zoom = 150.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->start_iter = 0;
	ptr->max_iter = 40;
	ptr->cur_y = 0;
	ptr->zx = 1;
	ptr->zy = 1;
	ptr->color.plur = COLOR_BLACK;
	ptr->color.start = COLOR_BLACK;
	ptr->color.final = COLOR_BLUE;
	ptr->pxl = 0.005;
	ptr->eps = 0.1;
	ptr->dpi = M_PI / 5;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		julia_init(t_frac *ptr)
{
	ptr->type_fract = JULIA;
	ptr->zoom = 150.00;
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
	ptr->color.final = COLOR_RED;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		put_menu_color_type(t_frac *f)
{
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "+/- Change color");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Z/X Change  plur");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Del Default scene");

}

void		init_mlx(t_frac *ptr, char *av)
{
	if (!(ptr->ptr = mlx_init()))
		error_exit("\033[0;31;1mError mlx_init\033[0m");
	if (!(ptr->win = mlx_new_window(ptr->ptr, WIDTH_WIN, HEIGHT_WIN, av)))
		error_exit("\033[0;31;1mError win_init\033[0m");
	if (!(ptr->img = mlx_new_image(ptr->ptr, WIDTH_WIN - WIDTH_MENU,
		HEIGHT_WIN)))
		error_exit("\033[0;31;1mError img_init\033[0m");
	if (!(ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bp_pix),
		&(ptr->size_line), &(ptr->endian))))
		error_exit("\033[0;31;1mError img_init\033[0m");
	if (!(ptr->menu.img = mlx_new_image(ptr->ptr, WIDTH_MENU, HEIGHT_MENU)))
		error_exit("\033[0;31;1mError img_init\033[0m");
	ptr->menu.data_addr = mlx_get_data_addr(ptr->menu.img,
	&(ptr->menu.bp_pix), &(ptr->menu.size_line), &(ptr->menu.endian));
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
	ptr->type_fract = MAND;
}
