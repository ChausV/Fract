/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:12:42 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 14:12:48 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
**	open(2)
*/
# include <fcntl.h>

/*
**	read(2), write(2), close(2), fork()
*/
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
**	malloc(), free(), exit(3)
*/
# include <stdlib.h>

/*
**	perror()
*/
# include <stdio.h>

/*
**	strerror()
*/
# include <string.h>

/*
**	math library
*/
# include <math.h>

/*
**	MinilibX library
*/
# include "mlx.h"

# define WIN_SIZE_FACTOR 300
# define THREADS_NUMBER 25
# define FRACTALS_NUMBER 7
# define KEY_FUNCTIONS_NUMBER 23

typedef struct s_win	t_win;
typedef struct s_fract	t_fract;
typedef struct s_thread	t_thread;
typedef struct s_change	t_change;
typedef struct s_build	t_build;

typedef	void	(*t_fr_calc_ptr)(t_build*);
typedef	void	(*t_key_func_ptr)(t_fract*);

struct		s_win
{
	void	*mlx_arr[3];
	int		dim;
	int		img_h;
	int		img_w;
	int		height;
	int		width;
	int		leg_w;
};
struct		s_fract
{
	t_win			*win;
	t_fr_calc_ptr	func;
	t_change		*ch_val;
	long double		start_x;
	long double		start_y;
	long double		end_x;
	long double		end_y;
	int				num_iter;
	long double		step;
	unsigned int	color;
	long double		zoom_depth;
	char			*img_data;
	long double		cx;
	long double		cy;
	int				j;
};
struct		s_thread
{
	t_fract		*fr;
	long double	y_start;
	long double	y_end;
	char		*image;
};
struct		s_change
{
	int				*key_arr;
	t_key_func_ptr	*kfun_arr;
	int				ch_iter;
	long double		zoom_in_step_limit;
	long double		zoom_out_step_limit;
	long double		ch_zoom;
	unsigned int	ch_color;
	long double		move_param;
	long double		ch_julia_param;
};
struct		s_build
{
	t_fract			*fr;
	long double		y_start;
	long double		y_end;
	long double		x_end;
	char			*image;
	long double		x;
	long double		y;
	long double		xn;
	long double		yn;
	long double		xt;
	long double		sq_xn;
	long double		sq_yn;
	int				i;
	int				n;
	unsigned int	color;
	char			*img;
};

char		*error_perror_null(const char *str);
int			error_perror_int(const char *str);
char		*error_str_null(const char *str);
int			error_str_int(const char *str);
void		usage_error(const char *name);

void		keyfunctions_init(t_key_func_ptr *arr);
void		keycodes_init(int *arr);
void		mand_init(t_fract *fr);
void		run_fractal(char *av);

int			graphics_window(char *file, t_fract *fr);
int			key_hook(int keycode, t_fract *fr);
int			mouse_hook(int button, int x, int y, t_fract *fr);
int			mouse_move(int x, int y, t_fract *fr);
int			close_win(void *fr);
void		clear_win(void **mlx_arr, int color, t_win *win);
void		button_win(void **mlx_arr, int color, t_win *win);
void		frame_win(void **mlx_arr, int color, t_win *win);
void		frame_fract_win(void **mlx_arr, int color, t_win *win);
void		draw_line(float *p0, float *p1, int color, void **mlx);

void		destroy_and_exit(t_fract *fr);
void		key_num_iter_increase(t_fract *fr);
void		key_num_iter_decrease(t_fract *fr);
void		key_zoom_in(t_fract *fr);
void		key_zoom_out(t_fract *fr);
void		key_color_increase(t_fract *fr);
void		key_color_decrease(t_fract *fr);
void		key_move_up(t_fract *fr);
void		key_move_down(t_fract *fr);
void		key_move_left(t_fract *fr);
void		key_move_right(t_fract *fr);
void		key_julia_re_increase(t_fract *fr);
void		key_julia_re_decrease(t_fract *fr);
void		key_julia_im_increase(t_fract *fr);
void		key_julia_im_decrease(t_fract *fr);
void		julia_mouse_flag(t_fract *fr);
void		key_switch_mandel(t_fract *fr);
void		key_switch_julia(t_fract *fr);
void		key_switch_bship(t_fract *fr);
void		key_switch_burnjulia(t_fract *fr);
void		key_switch_tricorn(t_fract *fr);
void		key_switch_burntricorn(t_fract *fr);

void		mouse_zoom_in(t_fract *fr, int x, int y);
void		mouse_zoom_out(t_fract *fr, int x, int y);

int			run_key_func(int key, t_fract *fr);
long double	absolute_val(long double z);
void		params_init(t_build *p, void *arg);

void		image_fractal(t_fract *fr, t_win *win);
void		mandel_calc(t_build *p);
void		julia_calc(t_build *p);
void		tricorn_calc(t_build *p);
void		burn_ship_calc(t_build *p);
void		burn_julia_calc(t_build *p);
void		burn_tricorn_calc(t_build *p);

#endif
