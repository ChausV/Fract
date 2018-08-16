/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:16:43 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/02 14:16:44 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

char	*error_perror_null(const char *str)
{
	perror(str);
	return (NULL);
}

int		error_perror_int(const char *str)
{
	perror(str);
	return (-1);
}

char	*error_str_null(const char *str)
{
	ft_putendl_fd(str, 2);
	return (NULL);
}

int		error_str_int(const char *str)
{
	ft_putendl_fd(str, 2);
	return (-1);
}

void	usage_error(const char *name)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" fractal ...", 2);
	ft_putendl_fd("---\nAvailable fractals:", 2);
	ft_putendl_fd("    mandelbrot", 2);
	ft_putendl_fd("    julia", 2);
	ft_putendl_fd("    burning_ship", 2);
	ft_putendl_fd("    burning_julia", 2);
	ft_putendl_fd("    tricorn", 2);
	ft_putendl_fd("    mandelbar", 2);
	ft_putendl_fd("    burning_tricorn", 2);
}
