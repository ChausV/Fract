/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:39:57 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 14:39:58 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	legend_line(void **mlx_arr, int color, t_win *win)
{
	float	p1[2];
	float	p2[2];
	float	p3[2];
	float	p4[2];

	p1[0] = win->leg_w;
	p1[1] = 0;
	p2[0] = win->leg_w;
	p2[1] = win->height;
	p3[0] = 0;
	p3[1] = 40;
	p4[0] = win->leg_w;
	p4[1] = 40;
	draw_line(p1, p2, color, mlx_arr);
	draw_line(p3, p4, color, mlx_arr);
	mlx_string_put(mlx_arr[0], mlx_arr[1], (win->leg_w / 2) - 70, 8, 0x009000,
																"How to use:");
}

static void	clear_win_part(void *mlx, void *win, int color, t_win *window)
{
	mlx_string_put(mlx, win, (window->leg_w / 2) - 70, 250, 0x009000,
																"Julia only:");
	mlx_string_put(mlx, win, 0, 280, 0xffd700, " Del, Page_Down");
	mlx_string_put(mlx, win, 160, 280, color, "to change Julia parameters");
	mlx_string_put(mlx, win, 0, 300, 0xffd700, " Home, End");
	mlx_string_put(mlx, win, 160, 300, color, "to change Julia parameters");
	mlx_string_put(mlx, win, 0, 320, 0xffd700, " J");
	mlx_string_put(mlx, win, 80, 320, color, "to enable/disable Julia-mouse");
	mlx_string_put(mlx, win, 0, 340, 0xffd700, " Move mouse");
	mlx_string_put(mlx, win, 160, 340, color, "to change Julia parameters");
}

void		clear_win(void **mlx_arr, int color, t_win *win)
{
	mlx_clear_window(mlx_arr[0], mlx_arr[1]);
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 50, 0xffd700, " Esc");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 50, color, "to exit()");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 70, 0xffd700, " Space");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 70, color, "to discard changes");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 90, 0xffd700, " +, -");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 90, color,
											"to change number of iterations");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 110, 0xffd700, " Q, A");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 110, color, "for static zoom");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 130, 0xffd700, " Arrows");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 130, color, "to move");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 150, 0xffd700, " Mouse wheel");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 130, 150, color,
														"for positioned zoom");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 170, 0xffd700, " W, S");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 170, color, "to change color");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 0, 190, 0xffd700, " 1 - 6");
	mlx_string_put(mlx_arr[0], mlx_arr[1], 80, 190, color, "to change fractal");
	clear_win_part(mlx_arr[0], mlx_arr[1], color, win);
	frame_win(mlx_arr, color, win);
	button_win(mlx_arr, color, win);
	frame_fract_win(mlx_arr, color, win);
	legend_line(mlx_arr, color, win);
}
