/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:39:45 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 14:39:46 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		destroy_and_exit(t_fract *fr)
{
	mlx_destroy_image(fr->win->mlx_arr[0], fr->win->mlx_arr[2]);
	mlx_destroy_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1]);
	exit(0);
}

int			starting_mlx(t_fract *fr, char *name)
{
	if (!(fr->win->mlx_arr[0] = mlx_init()))
	{
		return (error_str_int("mlx_init() error"));
	}
	if (!(fr->win->mlx_arr[1] = mlx_new_window(fr->win->mlx_arr[0],
										fr->win->width, fr->win->height, name)))
	{
		return (error_str_int("mlx_new_window() error"));
	}
	if (!(fr->win->mlx_arr[2] = mlx_new_image(fr->win->mlx_arr[0],
											fr->win->img_w, fr->win->img_h)))
	{
		mlx_destroy_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1]);
		return (error_str_int("mlx_new_image() error"));
	}
	return (0);
}

void		getting_img_d_addr(t_fract *fr)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	bits_per_pixel = 4;
	size_line = fr->win->img_w * bits_per_pixel;
	endian = 1;
	fr->img_data = mlx_get_data_addr(fr->win->mlx_arr[2], &bits_per_pixel,
														&size_line, &endian);
}

int			graphics_window(char *name, t_fract *fr)
{
	if (starting_mlx(fr, name) == -1)
	{
		return (-1);
	}
	getting_img_d_addr(fr);
	clear_win(fr->win->mlx_arr, 0xfffafa, fr->win);
	image_fractal(fr, fr->win);
	mlx_put_image_to_window(fr->win->mlx_arr[0], fr->win->mlx_arr[1],
								fr->win->mlx_arr[2], fr->win->leg_w + 11, 11);
	mlx_mouse_hook(fr->win->mlx_arr[1], mouse_hook, fr);
	mlx_hook(fr->win->mlx_arr[1], 2, 5, key_hook, fr);
	mlx_hook(fr->win->mlx_arr[1], 6, 0, mouse_move, fr);
	mlx_hook(fr->win->mlx_arr[1], 17, 1L << 17, close_win, fr);
	mlx_loop(fr->win->mlx_arr[0]);
	return (0);
}
