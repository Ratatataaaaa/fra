/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:27:49 by cwing             #+#    #+#             */
/*   Updated: 2020/11/09 08:06:20 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mand(t_frac *ptr)
{
	ptr->type_fract = MAND;
	ptr->zoom = 150.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom - 0.5;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->max_iter = 100;
	ptr->start_iter = 0;
	ptr->dev_iter = ptr->max_iter / 2;
	ptr->color.plural = COLOR_BLACK;
	ptr->color.start = COLOR_ORANG;
	ptr->color.one = COLOR_GOLD;
	ptr->color.two = COLOR_DARKTURQUIOSE;
	ptr->color.final = COLOR_PURPUR;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		init_ship(t_frac *ptr)
{
	ptr->type_fract = SHIP;
	ptr->zoom = 150.00;
	ptr->cx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom - 0.5;
	ptr->cy = -HEIGHT_MENU / 2 / ptr->zoom - 0.5;
	ptr->cur_y = 0;
	ptr->max_iter = 100;
	ptr->dev_iter = ptr->max_iter / 2;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->start_iter = 0;
	ptr->color.plural = COLOR_BLACK;
	ptr->color.start = COLOR_ORANG;
	ptr->color.final = COLOR_PURPUR;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		init_newt(t_frac *ptr)
{
	ptr->type_fract = NEWTON;
	ptr->cx = X0;
	ptr->cy = Y0;
	ptr->zoom = 0.005;
	ptr->eps = 0.1;
	ptr->dpi = M_PI / 5;
	ptr->max_iter = 80;
	ptr->color.plural = COLOR_BLACK;
	ptr->color.start = COLOR_GOLD;
	ptr->color.final = COLOR_BLACK;
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
}

void		init_juli(t_frac *ptr)
{
	ptr->type_fract = JULIA;
	ptr->zoom = 500.00;
	ptr->cx = -0.63;
	ptr->cy = -0.54;
	ptr->jx = -(WIDTH_WIN - WIDTH_MENU) / 2 / ptr->zoom;
	ptr->jy = -HEIGHT_MENU / 2 / ptr->zoom;
	ptr->start_iter = 0;
	ptr->max_iter = 100;
	ptr->dev_iter = ptr->max_iter / 2;
	ptr->cur_y = 0;
	ptr->zx = 0;
	ptr->zy = 0;
	ptr->color.plural = COLOR_BLACK;//(t_pixel){255, 255, 255, 0};
	ptr->color.start = COLOR_ORANG;
	ptr->color.final = COLOR_PURPUR;

	// ptr->color.start = (t_pixel){0, 0, 0, 1};
	// ptr->color.final = (t_pixel){255, 255, 255, 1};
	ptr->colors = NULL;
	ptr->colors = cache_colors(ptr);
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
	ptr->color.inter = 1;
	ptr->range_move = 0.01;
	ptr->max_iter = 50;
	ptr->threads = 16;
	ptr->clr_sw.red = -1;
	ptr->clr_sw.blue = -1;
	ptr->clr_sw.green = -1;
	ptr->clr_sw.start = -1;
	ptr->clr_sw.plural = -1;
	ptr->clr_sw.final = -1;
	ptr->type_fract = MAND;
}
