/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:47:25 by cwing             #+#    #+#             */
/*   Updated: 2020/11/09 08:05:08 by kain2250         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "keyhot.h"
# include "colorlist.h"
# include <stdbool.h>
# include <stdint.h>
# include <mlx.h>
# include <math.h>
# include <complex.h>
# include <pthread.h>
# include <limits.h>

# define WIDTH_WIN 2000
# define HEIGHT_WIN 1300
# define WIDTH_MENU 250
# define HEIGHT_MENU HEIGHT_WIN

# define RAD_STEP 0x090000
# define GREEN_STEP 0x000900
# define BLUE_STEP 0x000009

# define MAND 1
# define SHIP 2
# define JULIA 3
# define NEWTON 4

# define X0 (WIDTH_WIN - WIDTH_MENU) / 2
# define Y0 HEIGHT_WIN / 2

typedef struct		s_pixel
{
	uint8_t			blue;
	uint8_t			green;
	uint8_t			red;
	uint8_t			alfa;
}					t_pixel;

typedef struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef struct		s_color
{
	t_pixel			start;
	t_pixel			one;
	t_pixel			two;
	t_pixel			curent;
	t_pixel			final;
	t_pixel			plural;
	int				odd;
	int				inter;
}					t_color;

typedef struct		s_mouse
{
	int				is_pres_key;
	int				x;
	int				y;
	int				old_x;
	int				old_y;
}					t_mouse;

typedef struct		s_switch
{
	int				red;
	int				green;
	int				blue;
	int				start;
	int				plural;
	int				final;
}					t_switch;

typedef struct		s_menu
{
	void			*img;
	char			*data_addr;
	int				bp_pix;
	int				size_line;
	int				endian;
	int				x;
	int				y;
}					t_menu;

typedef struct		s_frac
{
	void			*ptr;
	void			*win;
	void			*img;
	uint8_t			*data_addr;
	int				bp_pix;
	int				size_line;
	int				endian;
	int				count_window;
	int				type_fract;
	char			*name;
	double			len_vect;
	double			zoom;

	double			zx;
	double			zy;

	double			cx;
	double			cy;

	double			jx;
	double			jy;

	double			nx;
	double			ny;

	double			pxl;
	double			eps;
	double			dpi;
	bool			smuze;
	double			range_move;
	int				iter;
	int				start_iter;
	int				max_iter;
	int				dev_iter;
	int				max_y;
	int				cur_y;
	int				threads;
	t_pixel			*colors;
	int				colors_size;
	struct s_frac	*new_win[11];
	struct s_color	color;
	struct s_mouse	mouse;
	struct s_switch	clr_sw;
	struct s_menu	menu;
}					t_frac;

int					main(int ac, char **av);
void				error_exit(char *str);
t_pixel				*cache_colors(t_frac *f);
void				thread_plus(t_frac *f, int key);

void				ch_start_color(t_frac *f, int key);
void				ch_menu_color(t_frac *f, int key);
void				ch_final_color(t_frac *f, int key);
int					find_color(t_frac *f, t_cord crd);
void				switch_color(t_frac *f, int key);
void				switch_area(t_frac *f, int key);
void				switch_color_preset(t_frac *f, int key);
void				put_menu_color_type(t_frac *f);

t_complex			mlt_complex(t_complex a, t_complex b);
t_complex			add_complex(t_complex a, t_complex b);
t_complex			abs_complex(t_complex z);
t_complex			sub_complex(t_complex a, t_complex b);
t_complex			dev_complex(t_complex a, t_complex b);
t_complex			pow_complex(t_complex a, int power);
t_complex			qtr_complex(t_complex a, t_complex b);
t_complex			sct_complex(t_complex z, char *real, char *imag);
double				mod_complex(t_complex z);
double				arg_complex(t_complex z);

void				init_mand(t_frac *ptr);
void				init_ship(t_frac *ptr);
void				init_juli(t_frac *ptr);
void				init_mlx(t_frac *f, char *av);
void				init_newt(t_frac *ptr);

void				spase_swich(t_frac *f);
void				open_win(t_frac *f, char *av);
void				close_win(t_frac *f);
int					cls(void *param);
void				switch_plur(t_frac *f);
void				switch_plur2(t_frac *f);

void				what_init(t_frac *f);
int					mouse_move(int x, int y, void *param);
void				keys0(int key, t_frac *f);
void				keys1(int key, t_frac *f);
int					key_press(int key, void *param);

void				key_img_move(t_frac *f, int key);
void				iter_plus(t_frac *f, int key);
void				swap_plur(t_frac *f, int key);
void				key_z_move(t_frac *f, int key);
void				mlx_loop_list(t_frac *f);

t_pixel				get_color(int i, t_pixel start, t_pixel end, t_frac *f, int vec);
void				put_pixel(int x, int y, t_frac *f, t_pixel color);
void				zero_back(t_frac *f, int menu_or_img);

void				complex_while(t_frac *f, t_complex z,
					t_complex c, t_cord crd);
void				julia_set(t_frac *f, t_cord crd);
void				other_set(t_frac *f, t_cord crd);
void				*draw_plur(void *param);
void				pars_frctl(char *av, t_frac *f);

void				put_menu(t_frac *f);

void				calc_plur(t_frac *f);
t_complex			mand_who(t_frac *f, t_complex z);

void				julia_dezoom(t_frac *f, int x, int y);
void				julia_zoom(t_frac *f, int x, int y);
void				other_dezoom(t_frac *f, int x, int y);
void				other_zoom(t_frac *f, int x, int y);
int					mouse_key(int button, int x, int y, void *param);

#endif
