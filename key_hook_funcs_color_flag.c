/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_funcs_04.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:16:01 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 14:16:02 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_color_increase(t_fract *fr)
{
	fr->color += fr->ch_val->ch_color;
}

void		key_color_decrease(t_fract *fr)
{
	fr->color -= fr->ch_val->ch_color;
}

void		julia_mouse_flag(t_fract *fr)
{
	if (fr->j == 0)
		fr->j = 1;
	else
		fr->j = 0;
}

void		key_switch_burntricorn(t_fract *fr)
{
	fr->func = &burn_tricorn_calc;
	mand_init(fr);
}
