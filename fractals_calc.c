/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:56:48 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/06 16:56:49 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_calc(t_build *p)
{
	p->xn = p->sq_xn - p->sq_yn + p->x;
	p->yn = (2.0L * p->xt * p->yn) + p->y;
}

void	julia_calc(t_build *p)
{
	p->xn = p->sq_xn - p->sq_yn + p->fr->cx;
	p->yn = (2.0L * p->xt * p->yn) + p->fr->cy;
}

void	tricorn_calc(t_build *p)
{
	p->xn = p->sq_xn - p->sq_yn + p->x;
	p->yn = -(2.0L * p->xt * p->yn) + p->y;
}

void	burn_ship_calc(t_build *p)
{
	p->xn = p->sq_xn - p->sq_yn + p->x;
	p->yn = (2.0L * absolute_val(p->xt * p->yn)) + p->y;
}

void	burn_julia_calc(t_build *p)
{
	p->xn = absolute_val(p->sq_xn - p->sq_yn + p->fr->cx);
	p->yn = absolute_val((2.0L * p->xt * p->yn) + p->fr->cy);
}
