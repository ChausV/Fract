/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:10:20 by vchaus            #+#    #+#             */
/*   Updated: 2018/03/01 20:10:22 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keycodes_init(int *arr)
{
	arr[0] = 53;
	arr[1] = 49;
	arr[2] = 24;
	arr[3] = 27;
	arr[4] = 12;
	arr[5] = 0;
	arr[6] = 13;
	arr[7] = 1;
	arr[8] = 125;
	arr[9] = 126;
	arr[10] = 124;
	arr[11] = 123;
	arr[12] = 119;
	arr[13] = 115;
	arr[14] = 121;
	arr[15] = 117;
	arr[16] = 38;
	arr[17] = 18;
	arr[18] = 19;
	arr[19] = 20;
	arr[20] = 21;
	arr[21] = 23;
	arr[22] = 22;
}

void	keyfunctions_init(t_key_func_ptr *arr)
{
	arr[0] = &destroy_and_exit;
	arr[1] = &mand_init;
	arr[2] = &key_num_iter_increase;
	arr[3] = &key_num_iter_decrease;
	arr[4] = &key_zoom_in;
	arr[5] = &key_zoom_out;
	arr[6] = &key_color_increase;
	arr[7] = &key_color_decrease;
	arr[8] = &key_move_down;
	arr[9] = &key_move_up;
	arr[10] = &key_move_right;
	arr[11] = &key_move_left;
	arr[12] = &key_julia_re_decrease;
	arr[13] = &key_julia_re_increase;
	arr[14] = &key_julia_im_increase;
	arr[15] = &key_julia_im_decrease;
	arr[16] = &julia_mouse_flag;
	arr[17] = &key_switch_mandel;
	arr[18] = &key_switch_julia;
	arr[19] = &key_switch_bship;
	arr[20] = &key_switch_burnjulia;
	arr[21] = &key_switch_tricorn;
	arr[22] = &key_switch_burntricorn;
}

int		run_key_func(int key, t_fract *fr)
{
	int				i;
	t_key_func_ptr	func;

	i = 0;
	while (i < KEY_FUNCTIONS_NUMBER)
	{
		if (key == fr->ch_val->key_arr[i])
		{
			func = fr->ch_val->kfun_arr[i];
			func(fr);
			return (0);
		}
		else
			i++;
	}
	return (1);
}
