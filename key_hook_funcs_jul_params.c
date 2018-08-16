/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_funcs_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:15:54 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 14:15:54 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_julia_re_increase(t_fract *fr)
{
	fr->cx += fr->ch_val->ch_julia_param;
}

void		key_julia_re_decrease(t_fract *fr)
{
	fr->cx -= fr->ch_val->ch_julia_param;
}

void		key_julia_im_increase(t_fract *fr)
{
	fr->cy += fr->ch_val->ch_julia_param;
}

void		key_julia_im_decrease(t_fract *fr)
{
	fr->cy -= fr->ch_val->ch_julia_param;
}
