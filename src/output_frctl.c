/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_frctl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:25:25 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 00:18:47 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint8_t	get_light(uint8_t start, uint8_t end, double percentage)
{
	int		ret;

	ret = (1 - percentage) * start + (percentage * end);
	return (ret);
}

t_pixel			get_color(int i, t_pixel start, t_pixel end, t_frctl *f)
{
	t_pixel		pixel;
	double		percentage;

	
	percentage = ft_percent(f->start_iter, f->max_iter, i);
	pixel.red = get_light(start.red, end.red, percentage);
	pixel.green = get_light(start.green, end.green, percentage);
	pixel.blue = get_light(start.blue, end.blue, percentage);
	return (pixel);
}

void		put_pixel(int x, int y, t_frctl *f, t_pixel color)
{
	int		i;

	if (x > 0 && x < (WIDTH_WIN - WIDTH_MENU) && y >= 0 && y < HEIGHT_WIN)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = color.red;
		f->data_addr[++i] = color.green;
		f->data_addr[++i] = color.blue;
		f->data_addr[++i] = 0;
	}
}

void		output_background(t_frctl *f, int menu_or_img)
{
	if (menu_or_img == 1)
		ft_bzero(f->menu.data_addr, WIDTH_MENU * HEIGHT_MENU *
		(f->menu.bits_per_pixel / 8));
	else
		ft_bzero(f->data_addr, (WIDTH_WIN - WIDTH_MENU) * HEIGHT_WIN *
		(f->bits_per_pixel / 8));
}
