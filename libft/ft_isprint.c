/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:59:56 by vchaus            #+#    #+#             */
/*   Updated: 2017/11/16 10:59:57 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	if (c == -1)
		return (0);
	if ((c >= ' ') && (c <= '~'))
		return (1);
	return (0);
}
