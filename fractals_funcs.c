/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:57:09 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/06 16:57:10 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	absolute_val(long double z)
{
	if (z >= 0)
		return (z);
	else
		return (-z);
}

void		params_init(t_build *p, void *arg)
{
	p->fr = ((t_thread*)arg)->fr;
	p->y_start = ((t_thread*)arg)->y_start;
	p->y_end = ((t_thread*)arg)->y_end - (p->fr->step / 2.0L);
	p->x_end = p->fr->end_x - (p->fr->step / 2.0L);
	p->image = ((t_thread*)arg)->image;
	p->x = p->fr->start_x;
	p->y = p->y_start;
	p->i = 0;
	p->n = 0;
	p->img = p->image;
}

void		burn_tricorn_calc(t_build *p)
{
	p->xn = absolute_val(p->sq_xn - p->sq_yn + p->x);
	p->yn = absolute_val(-(2.0L * p->xt * p->yn) + p->y);
}
