/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_funcs_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:15:19 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 14:15:27 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		key_num_iter_increase(t_fract *fr)
{
	fr->num_iter += fr->ch_val->ch_iter;
	ft_putstr("iterations number is ");
	ft_putnbr(fr->num_iter);
	ft_putstr("\n");
}

void		key_num_iter_decrease(t_fract *fr)
{
	if (fr->num_iter > fr->ch_val->ch_iter)
		fr->num_iter -= fr->ch_val->ch_iter;
	ft_putstr("iterations number is ");
	ft_putnbr(fr->num_iter);
	ft_putstr("\n");
}

static void	key_zoom(t_fract *fr, long double ch)
{
	long double	dx;
	long double	dy;

	dx = (fr->start_x + fr->end_x) / 2.0L;
	dy = (fr->start_y + fr->end_y) / 2.0L;
	fr->start_x = (fr->start_x * ch) + (dx * (1.0L - ch));
	fr->start_y = (fr->start_y * ch) + (dy * (1.0L - ch));
	fr->end_x = (fr->end_x * ch) + (dx * (1.0L - ch));
	fr->end_y = (fr->end_y * ch) + (dy * (1.0L - ch));
	fr->step *= ch;
	fr->zoom_depth /= ch;
}

void		key_zoom_in(t_fract *fr)
{
	if (fr->step < fr->ch_val->zoom_in_step_limit)
	{
		ft_putstr("You are close enough!\n");
	}
	else
	{
		key_zoom(fr, 1.0L / fr->ch_val->ch_zoom);
	}
}

void		key_zoom_out(t_fract *fr)
{
	if (fr->step > fr->ch_val->zoom_out_step_limit)
	{
		ft_putstr("You are far enough!\n");
	}
	else
	{
		key_zoom(fr, fr->ch_val->ch_zoom);
	}
}
