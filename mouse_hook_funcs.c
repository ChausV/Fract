/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:23:33 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 15:23:35 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	mouse_zoom(t_fract *fr, long double ch, int x, int y)
{
	long double	dx;
	long double	dy;

	dx = (long double)(x - (fr->win->leg_w + 11)) * (fr->end_x - fr->start_x) /
									(long double)fr->win->img_w + fr->start_x;
	dy = (long double)(y - 11) * (fr->end_y - fr->start_y) /
								(long double)fr->win->img_h + fr->start_y;
	fr->start_x = (fr->start_x * ch) + (dx * (1.0L - ch));
	fr->start_y = (fr->start_y * ch) + (dy * (1.0L - ch));
	fr->end_x = (fr->end_x * ch) + (dx * (1.0L - ch));
	fr->end_y = (fr->end_y * ch) + (dy * (1.0L - ch));
	fr->step *= ch;
	fr->zoom_depth /= ch;
}

void		mouse_zoom_in(t_fract *fr, int x, int y)
{
	if (fr->step < fr->ch_val->zoom_in_step_limit)
	{
		ft_putstr("You are close enough!\n");
	}
	else
	{
		mouse_zoom(fr, 1.0L / fr->ch_val->ch_zoom, x, y);
		image_fractal(fr, fr->win);
		mlx_put_image_to_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1],
			fr->win->mlx_arr[2], fr->win->leg_w + 11, 11);
	}
}

void		mouse_zoom_out(t_fract *fr, int x, int y)
{
	if (fr->step > fr->ch_val->zoom_out_step_limit)
	{
		ft_putstr("You are far enough!\n");
	}
	else
	{
		mouse_zoom(fr, fr->ch_val->ch_zoom, x, y);
		image_fractal(fr, fr->win);
		mlx_put_image_to_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1],
			fr->win->mlx_arr[2], fr->win->leg_w + 11, 11);
	}
}
