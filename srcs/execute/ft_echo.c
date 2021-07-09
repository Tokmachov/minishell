/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:55:01 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 14:45:54 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	print_result(char **comand, int i, int fd)
{
	while (comand[i] != NULL)
	{
		ft_putstr_fd(comand[i], fd);
		i++;
		if (comand[i] != NULL)
			ft_putchar_fd(' ', fd);
	}
}

void		ft_echo(char **comand, int fd)
{
	int	i;

	if (comand[1] == NULL)
		ft_putchar_fd('\n', fd);
	else if (ft_strcmp(comand[1], "-n") == 1)
	{
		if (comand[2] == NULL)
			ft_putchar_fd('\0', fd);
		else
		{
			i = 2;
			print_result(comand, i, fd);
		}
	}
	else
	{
		i = 1;
		print_result(comand, i, fd);
		ft_putchar_fd('\n', fd);
	}
}
