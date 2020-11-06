/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:18:51 by cwing             #+#    #+#             */
/*   Updated: 2020/11/06 13:07:21 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_menu_plur_change_color_switch(t_frac *f)
{
	if (f->clr_sw.plur == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "H - Clr_Plur ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "H - Clr_Plur OFF");
	if (f->clr_sw.final == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "N - Clr_Cant ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "N - Clr_Cant OFF");
	if (f->clr_sw.start == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "T - Clr_Backgr ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "T - Clr_Backgr OFF");
}

void				put_menu_keycode(t_frac *f)
{
	char			*str;

	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "E Thread + 1");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Q Thread - 1");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Threads - ");
	mlx_string_put(f->ptr, f->win, f->menu.x + 100, f->menu.y,
	0xffffff, (str = ft_itoa(f->threads)));
	free(str);
	if (f->threads == 2)
		mlx_string_put(f->ptr, f->win, f->menu.x + 115, f->menu.y,
		0xffffff, "min");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "A,W,D,S - Shift_Plur ");
	if (f->mouse.is_pres_key == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "Space - Move Plur ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xffffff, "Space - Move Plur OFF");
}

void				put_menu_status_plur(t_frac *f)
{
	char			*str;

	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "]   Itter + 10");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "[   Itter - 10");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Itter - ");
	mlx_string_put(f->ptr, f->win, f->menu.x + 80, f->menu.y,
	0xffffff, (str = ft_itoa(f->max_iter)));
	if (f->max_iter == 10)
		mlx_string_put(f->ptr, f->win, f->menu.x + 110, f->menu.y,
		0xffffff, "min");
	free(str);
	mlx_string_put(f->ptr, f->win, f->menu.x + 140, f->menu.y,
	0xffffff, (str = ft_itoa(f->type_fract)));
	free(str);
}

void				put_menu_color_switch(t_frac *f)
{
	if (f->clr_sw.red == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xbbaaaa, "R - Rad_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		0xbb1100, "R - Rad_Canal OFF");
	if (f->clr_sw.green == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		0x00bb00, "G - Green_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		0x00bb00, "G - Green_Canal OFF");
	if (f->clr_sw.blue == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		0x0000bb, "B - Blue_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		0x0000bb, "B - Blue_Canal OFF");
}

void				put_menu(t_frac *f)
{
	int				*image;
	register int	i;

	image = (int *)(f->menu.data_addr);
	i = 0;
	while (i < HEIGHT_MENU * WIDTH_MENU)
		image[i++] = 0x000000;
	mlx_put_image_to_window(f->ptr, f->win, f->menu.img,
	WIDTH_WIN - WIDTH_MENU, 0);
	f->menu.y = 0;
	f->menu.x = WIDTH_WIN - WIDTH_MENU + 5;
	switch_plur(f);
	put_menu_color_switch(f);
	put_menu_plur_change_color_switch(f);
	put_menu_color_type(f);
	put_menu_status_plur(f);
	put_menu_keycode(f);
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "'Enter' - new window");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	0xffffff, "Scroll - Zoom");
}
