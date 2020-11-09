/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_frctl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 22:25:25 by cwing             #+#    #+#             */
/*   Updated: 2020/11/09 08:16:54 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint8_t	get_light(uint8_t start, uint8_t end, double percentage)
{
	int		ret;

	ret = (1 - percentage) * start + (percentage * end);
	return (ret);
}

t_pixel			get_color(int i, t_pixel start, t_pixel end, t_frac *f, int vec)
{
	t_pixel		pixel;
	double		percentage;
	
	
	percentage = ft_percent(0, f->dev_iter, i);
	pixel.red = get_light(start.red, end.red, percentage);
	pixel.green = get_light(start.green, end.green, percentage);
	pixel.blue = get_light(start.blue, end.blue, percentage);
	return (pixel);
}

void			put_pixel(int x, int y, t_frac *f, t_pixel color)
{
	int		i;

	if (x > 0 && x < (WIDTH_WIN - WIDTH_MENU) && y >= 0 && y < HEIGHT_WIN)
	{
		i = (x * f->bp_pix / 8) + (y * f->size_line);
		f->data_addr[i] = color.red;
		f->data_addr[++i] = color.green;
		f->data_addr[++i] = color.blue;
		f->data_addr[++i] = (f->smuze) ? color.alfa + 200 : 0;
	}
}

void			zero_back(t_frac *f, int menu_or_img)
{
	if (menu_or_img == 1)
		ft_bzero(f->menu.data_addr, WIDTH_MENU * HEIGHT_MENU *
		(f->menu.bp_pix / 8));
	else
		ft_bzero(f->data_addr, (WIDTH_WIN - WIDTH_MENU) * HEIGHT_WIN *
		(f->bp_pix / 8));
}

void			put_menu_color_type(t_frac *f)
{
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "+/- Change color");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Z/X Change plural");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Del Default scene");
}
