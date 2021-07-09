/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_cond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:16:54 by hrema             #+#    #+#             */
/*   Updated: 2020/12/03 14:52:18 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		export_cond(t_comand *comand)
{
	int	i;
	int	res;

	if (comand->comand[1] == NULL)
		export_print(comand->output);
	else
	{
		i = 0;
		while (comand->comand[++i])
		{
			if ((res = ft_export(comand->comand[i])) == 2)
			{
				g_process_exit_code = res;
				break ;
			}
			else if (res == -1)
			{
				g_process_exit_code = 1;
				exit(EXIT_FAILURE);
			}
			else if (res == 1)
				g_process_exit_code = res;
		}
	}
	return (g_process_exit_code);
}

int		unset_cond(t_comand *comand)
{
	int	i;
	int	res;

	i = 1;
	while (comand->comand[i])
	{
		if ((res = ft_unset(comand->comand[i])) == 2)
		{
			g_process_exit_code = res;
			break ;
		}
		else if (res == -1)
		{
			g_process_exit_code = 1;
			exit(EXIT_FAILURE);
		}
		else if (res == 1)
			g_process_exit_code = res;
		i++;
	}
	return (g_process_exit_code);
}

void	exit_cond(t_comand *comand)
{
	if (comand->comand[1] != NULL)
	{
		if (comand->comand[2] != NULL)
			ft_exit_with_error("exit: too many argument");
		if (ft_isnum_str(comand->comand[1]))
		{
			if (comand->comand[1][0] == '-')
				exit(255 + ft_atoi(comand->comand[1]) + 1);
			else
				exit(ft_atoi(comand->comand[1]));
		}
		else
		{
			ft_print_error("exit: numeric argument required");
			exit(255);
		}
	}
	else
		exit(g_process_exit_code);
}

void	pwd_cond(t_comand *comand)
{
	if (comand->comand[1] && comand->comand[1][0] == '-')
		ft_exit_with_error("invalid option");
	ft_pwd(comand->output);
}
