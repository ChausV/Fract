/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:22:36 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/06 18:22:38 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	key_hook(int keycode, t_fract *fr)
{
	if (run_key_func(keycode, fr) == 0)
	{
		image_fractal(fr, fr->win);
		mlx_put_image_to_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1],
								fr->win->mlx_arr[2], fr->win->leg_w + 11, 11);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fract *fr)
{
	if ((button == 1 || button == 2) &&
		(x > (fr->win->leg_w / 2) - 70 && x < (fr->win->leg_w / 2) + 70) &&
		(y > fr->win->height - 90 && y < fr->win->height - 30))
	{
		destroy_and_exit(fr);
	}
	else if ((button == 5) &&
		(x > fr->win->leg_w + 10 && x < fr->win->width - 9) &&
		(y > 10 && y < fr->win->height - 9))
	{
		mouse_zoom_in(fr, x, y);
	}
	else if ((button == 4) &&
		(x > fr->win->leg_w + 10 && x < fr->win->width - 9) &&
		(y > 10 && y < fr->win->height - 9))
	{
		mouse_zoom_out(fr, x, y);
	}
	return (0);
}

int	mouse_move(int x, int y, t_fract *fr)
{
	static int	prevx = 0;
	static int	prevy = 0;

	if ((x > fr->win->leg_w + 10 && x < fr->win->width - 9) &&
		(y > 10 && y < fr->win->height - 9))
	{
		if (fr->j)
		{
			if (x > prevx)
				fr->cy += 0.05L;
			else if (x < prevx)
				(fr->cy -= 0.05L);
			if (y > prevy)
				fr->cx -= 0.05L;
			else if (y < prevy)
				fr->cx += 0.05L;
			prevx = x;
			prevy = y;
			image_fractal(fr, fr->win);
			mlx_put_image_to_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1],
			fr->win->mlx_arr[2], fr->win->leg_w + 11, 11);
		}
	}
	return (0);
}

int	close_win(void *fr)
{
	destroy_and_exit(fr);
	return (0);
}
