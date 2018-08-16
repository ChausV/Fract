/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_win_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:08:26 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/06 19:08:27 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	button_win(void **mlx_arr, int color, t_win *win)
{
	float	p1[2];
	float	p2[2];
	float	p3[2];
	float	p4[2];

	p1[0] = (win->leg_w / 2) - 70;
	p1[1] = win->height - 90;
	p2[0] = (win->leg_w / 2) + 70;
	p2[1] = win->height - 90;
	p3[0] = (win->leg_w / 2) - 70;
	p3[1] = win->height - 30;
	p4[0] = (win->leg_w / 2) + 70;
	p4[1] = win->height - 30;
	draw_line(p1, p2, color, mlx_arr);
	draw_line(p3, p4, color, mlx_arr);
	draw_line(p1, p3, color, mlx_arr);
	draw_line(p2, p4, color, mlx_arr);
	mlx_string_put(mlx_arr[0], mlx_arr[1], (win->leg_w / 2) - 60,
		win->height - 82, 0xffd700, " click");
	mlx_string_put(mlx_arr[0], mlx_arr[1], (win->leg_w / 2) + 10,
		win->height - 82, color, "here");
	mlx_string_put(mlx_arr[0], mlx_arr[1], (win->leg_w / 2) - 50,
		win->height - 62, color, " to QUIT");
}

void	frame_win(void **mlx_arr, int color, t_win *win)
{
	float	p1[2];
	float	p2[2];
	float	p3[2];
	float	p4[2];

	p1[0] = 0;
	p1[1] = 0;
	p2[0] = win->width - 1;
	p2[1] = 0;
	p3[0] = 0;
	p3[1] = win->height - 1;
	p4[0] = win->width - 1;
	p4[1] = win->height - 1;
	draw_line(p1, p2, color, mlx_arr);
	draw_line(p3, p4, color, mlx_arr);
	draw_line(p1, p3, color, mlx_arr);
	draw_line(p2, p4, color, mlx_arr);
}

void	frame_fract_win(void **mlx_arr, int color, t_win *win)
{
	float	p1[2];
	float	p2[2];
	float	p3[2];
	float	p4[2];

	p1[0] = win->leg_w + 10;
	p1[1] = 10;
	p2[0] = win->width - 9;
	p2[1] = 10;
	p3[0] = win->leg_w + 10;
	p3[1] = win->height - 9;
	p4[0] = win->width - 9;
	p4[1] = win->height - 9;
	draw_line(p1, p2, color, mlx_arr);
	draw_line(p3, p4, color, mlx_arr);
	draw_line(p1, p3, color, mlx_arr);
	draw_line(p2, p4, color, mlx_arr);
}
