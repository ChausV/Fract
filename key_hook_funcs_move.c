/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_funcs_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:15:46 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/02 14:15:47 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key_move_up(t_fract *fr)
{
	fr->start_y -= (fr->ch_val->move_param / fr->zoom_depth);
	fr->end_y -= (fr->ch_val->move_param / fr->zoom_depth);
}

void		key_move_down(t_fract *fr)
{
	fr->start_y += (fr->ch_val->move_param / fr->zoom_depth);
	fr->end_y += (fr->ch_val->move_param / fr->zoom_depth);
}

void		key_move_left(t_fract *fr)
{
	fr->start_x -= (fr->ch_val->move_param / fr->zoom_depth);
	fr->end_x -= (fr->ch_val->move_param / fr->zoom_depth);
}

void		key_move_right(t_fract *fr)
{
	fr->start_x += (fr->ch_val->move_param / fr->zoom_depth);
	fr->end_x += (fr->ch_val->move_param / fr->zoom_depth);
}
