/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:47:25 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/11/04 00:07:07 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH_WIN 750
# define HEIGHT_WIN 500
# define WIDTH_MENU 250
# define HEIGHT_MENU HEIGHT_WIN

# define RAD_STEP 0x050000
# define GREEN_STEP 0x000500
# define BLUE_STEP 0x000005

# define MAND1 1
# define MAND2 2
# define MAND3 3
# define MAND4 4
# define MAND5 5
# define MAND6 6
# define MAND7 7
# define MAND8 8
# define JULIA 9
# define SHIP 10
# define NEWTON 11

# include "libft.h"
# include "keyhot.h"
# include "colorlist.h"
# include <stdbool.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_pixel
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
	uint8_t			alfa;
}					t_pixel;

typedef struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_coodrinate
{
	int				x;
	int				y;
}					t_crd;

typedef struct		s_color
{
	t_pixel			start;
	t_pixel			curent;
	t_pixel			final;
	t_pixel			plur;
	int				odd;
	int				interpol;
}					t_color;

typedef struct		s_mouse
{
	int				is_pres_key;
	int				x;
	int				y;
	int				prew_x;
	int				prew_y;
}					t_mouse;

typedef struct		s_switch
{
	int				red;
	int				green;
	int				blue;
	int				start;
	int				plur;
	int				final;
}					t_clr_sw;

typedef struct		s_menu
{
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				x;
	int				y;
}					t_menu;

typedef struct		s_frctl
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
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

	double			range_move;
	int				iter;
	int				start_iter;
	int				max_iter;
	int				colors_size;
	int				max_y;
	int				cur_y;
	int				threads;
	t_pixel			*colors;
	struct s_frctl	*new_win[11];
	struct s_color	color;
	struct s_mouse	mouse;
	struct s_switch	clr_sw;
	struct s_menu	menu;
}					t_frctl;

int					main(int ac, char **av);
void				error_exit(char *str);
t_pixel				*cache_colors(t_frctl *f);

void				change_color_start(t_frctl *f, int key);
void				change_color_m(t_frctl *f, int key);
void				change_color_final(t_frctl *f, int key);
int					find_color(t_frctl *f, t_crd crd);
void				switch_color(t_frctl *f, int key);
void				switch_area(t_frctl *f, int key);
void				switch_color_preset(t_frctl *f, int key);
void				put_menu_color_type(t_frctl *f);

t_complex			multi_complex(t_complex a, t_complex b);
t_complex			addit_complex(t_complex a, t_complex b);
t_complex			abs_complex(t_complex z);
t_complex			subtraction_complex(t_complex a, t_complex b);
double				mod_complex(t_complex z);
t_complex			devision_complex(t_complex a, t_complex b);
t_complex			pow_complex(t_complex a, int power);


t_complex			quatro_complex(t_complex a, t_complex b);
t_complex			sin_cos_tg_complex(t_complex z, char *real,
						char *imag);

void				mand_init(t_frctl *ptr);
void				fire_ship_init(t_frctl *ptr);
void				julia_init(t_frctl *ptr);
void				init_mlx(t_frctl *f, char *av);
void				newton_init(t_frctl *ptr);

void				thread_plus(t_frctl *f, int key);
void				spase_swich(t_frctl *f);
void				open_new_window(t_frctl *f, char *av);
void				close_win(t_frctl *f);
int					cls(void *param);
void				switch_plur(t_frctl *f);
void				switch_plur2(t_frctl *f);

void				what_init(t_frctl *f);
int					mouse_move(int x, int y, void *param);
void				keys0(int key, t_frctl *f);
void				keys1(int key, t_frctl *f);
int					key_press(int key, void *param);

void				key_img_move(t_frctl *f, int key);
void				iter_plus(t_frctl *f, int key);
void				swap_plur(t_frctl *f, int key);
void				key_z_move(t_frctl *f, int key);
void				mlx_loop_list(t_frctl *f);

t_pixel				get_color(int i, t_pixel start, t_pixel end, t_frctl *f);
void				put_pixel(int x, int y, t_frctl *f, t_pixel color);
void				output_background(t_frctl *f, int menu_or_img);

void				complex_while(t_frctl *f, t_complex z,
					t_complex c, t_crd crd);
void				julia_set(t_frctl *f, t_crd crd);
void				other_set(t_frctl *f, t_crd crd);
void				*draw_plur(void *param);
void				pars_frctl(char *av, t_frctl *f);

void				put_menu(t_frctl *f);

void				calc_plur(t_frctl *f);
t_complex			mand_who(t_frctl *f, t_complex z);

void				julia_dezoom(t_frctl *f, int x, int y);
void				julia_zoom(t_frctl *f, int x, int y);
void				other_dezoom(t_frctl *f, int x, int y);
void				other_zoom(t_frctl *f, int x, int y);
int					mouse_key(int button, int x, int y, void *param);

#endif
