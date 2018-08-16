/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:18:07 by vchaus            #+#    #+#             */
/*   Updated: 2018/02/12 14:18:08 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static int	forking(int ac, char **av)
{
	pid_t	pid;

	if (ac == 1)
	{
		run_fractal(av[0]);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			error_perror_null("fork() error");
			return (-1);
		}
		else if (pid != 0)
			run_fractal(av[0]);
		else
			return (forking(--ac, ++av));
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 1)
	{
		usage_error(av[0]);
	}
	else
	{
		forking(--ac, ++av);
	}
	return (0);
}
