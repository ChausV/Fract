/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_funcs_05.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:02:46 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 16:02:46 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_switch_mandel(t_fract *fr)
{
	fr->func = &mandel_calc;
	mand_init(fr);
}

void		key_switch_julia(t_fract *fr)
{
	fr->func = &julia_calc;
	mand_init(fr);
}

void		key_switch_bship(t_fract *fr)
{
	fr->func = &burn_ship_calc;
	mand_init(fr);
}

void		key_switch_burnjulia(t_fract *fr)
{
	fr->func = &burn_julia_calc;
	mand_init(fr);
}

void		key_switch_tricorn(t_fract *fr)
{
	fr->func = &tricorn_calc;
	mand_init(fr);
}
