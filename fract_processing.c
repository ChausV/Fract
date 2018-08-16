/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:35:29 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 14:35:30 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static int	name_check_part(char *name, t_fract *fr, char **names,
														t_fr_calc_ptr *funcs)
{
	int	i;

	i = 0;
	while (i < FRACTALS_NUMBER)
	{
		if (ft_strcmp(name, names[i]) == 0)
		{
			fr->func = funcs[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int			name_check(char *name, t_fract *fr)
{
	char			*frac_names[FRACTALS_NUMBER];
	t_fr_calc_ptr	frac_funcs[FRACTALS_NUMBER];

	frac_names[0] = "mandelbrot";
	frac_names[1] = "julia";
	frac_names[2] = "burning_ship";
	frac_names[3] = "burning_julia";
	frac_names[4] = "tricorn";
	frac_names[5] = "mandelbar";
	frac_names[6] = "burning_tricorn";
	frac_funcs[0] = &mandel_calc;
	frac_funcs[1] = &julia_calc;
	frac_funcs[2] = &burn_ship_calc;
	frac_funcs[3] = &burn_julia_calc;
	frac_funcs[4] = &tricorn_calc;
	frac_funcs[5] = &tricorn_calc;
	frac_funcs[6] = &burn_tricorn_calc;
	if (name_check_part(name, fr, frac_names, frac_funcs) == 1)
		return (1);
	return (0);
}

void		mand_init(t_fract *fr)
{
	fr->win->dim = WIN_SIZE_FACTOR;
	fr->win->leg_w = 480;
	fr->win->img_h = 2 * fr->win->dim;
	fr->win->img_w = 2 * fr->win->dim;
	fr->win->height = fr->win->img_h + 20;
	fr->win->width = fr->win->leg_w + 20 + fr->win->img_w;
	fr->ch_val->ch_iter = 10;
	fr->ch_val->zoom_in_step_limit = 0.0000000000000002L;
	fr->ch_val->zoom_out_step_limit = 10.0L;
	fr->ch_val->ch_zoom = 1.2L;
	fr->ch_val->ch_color = 15000;
	fr->ch_val->move_param = 0.2L;
	fr->ch_val->ch_julia_param = 0.02L;
	fr->start_x = -2.0L;
	fr->end_x = 2.0L;
	fr->start_y = -2.0L;
	fr->end_y = 2.0L;
	fr->num_iter = 30;
	fr->step = (fr->end_y - fr->start_y) / (long double)fr->win->img_h;
	fr->color = 1000000;
	fr->zoom_depth = 1.0L;
	fr->cx = -0.4L;
	fr->cy = 0.6L;
	fr->j = 0;
}

void		run_fractal(char *av)
{
	t_fract			fr;
	t_win			win;
	t_change		ch_val;
	int				keycodes[KEY_FUNCTIONS_NUMBER];
	t_key_func_ptr	keyfunctions[KEY_FUNCTIONS_NUMBER];

	fr.win = &win;
	fr.ch_val = &ch_val;
	fr.ch_val->key_arr = keycodes;
	fr.ch_val->kfun_arr = keyfunctions;
	mand_init(&fr);
	keycodes_init(keycodes);
	keyfunctions_init(keyfunctions);
	if (name_check(av, &fr) == 0)
	{
		usage_error("./fractol");
		return ;
	}
	else
	{
		graphics_window(av, &fr);
	}
}
