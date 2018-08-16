/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:50:18 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 15:50:19 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <pthread.h>

void	fractal_calc(t_build *p)
{
	while ((p->i)++ < p->fr->num_iter)
	{
		p->sq_xn = p->xn * p->xn;
		p->sq_yn = p->yn * p->yn;
		p->xt = p->xn;
		p->fr->func(p);
		if ((p->sq_xn + p->sq_yn) > 4.0L)
		{
			p->color = p->fr->color + (p->i * 15000);
			ft_memcpy(p->img, &(p->color), 4);
			p->i = p->fr->num_iter;
		}
	}
}

void	*image_fractal_block(void *arg)
{
	t_build	p;

	params_init(&p, arg);
	while (p.y < p.y_end)
	{
		while (p.x < p.x_end)
		{
			p.xn = p.x;
			p.yn = p.y;
			ft_bzero(p.img, 4);
			fractal_calc(&p);
			p.img += 4;
			p.x += p.fr->step;
			p.i = 0;
		}
		p.x = p.fr->start_x;
		p.y += p.fr->step;
		(p.n)++;
		p.img = p.image + (p.n * (p.fr->win->img_w * 4));
	}
	return (NULL);
}

void	join_img_threads(t_fract *fr, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < THREADS_NUMBER)
	{
		if (pthread_join(thread[i], NULL))
		{
			error_str_null("pthread_join() error");
			destroy_and_exit(fr);
		}
		i++;
	}
}

void	image_fractal(t_fract *fr, t_win *win)
{
	t_thread	args[THREADS_NUMBER];
	pthread_t	thread[THREADS_NUMBER];
	int			i;

	i = 0;
	while (i < THREADS_NUMBER)
	{
		(args[i]).fr = fr;
		(args[i]).y_start = fr->start_y + ((long double)(i * (win->img_h /
												THREADS_NUMBER)) * fr->step);
		(args[i]).y_end = fr->start_y + ((long double)((i + 1) * (win->img_h /
												THREADS_NUMBER)) * fr->step);
		(args[i]).image = fr->img_data + (i * (win->img_h / THREADS_NUMBER) *
														(win->img_w * 4));
		if (pthread_create(&thread[i], NULL, image_fractal_block,
															(void*)&args[i]))
		{
			error_str_null("pthread_create() error");
			destroy_and_exit(fr);
		}
		i++;
	}
	join_img_threads(fr, thread);
}
