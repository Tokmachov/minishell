/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:24:18 by hrema             #+#    #+#             */
/*   Updated: 2020/12/03 14:30:22 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	simple_child_process(t_comand *comand)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		ft_print_error(strerror(errno));
	else if (child_pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		check_some_our_comand(comand);
		exit(EXIT_SUCCESS);
	}
	else
	{
		parent_process(child_pid, comand);
	}
}

static void	close_fd(t_comand *comand)
{
	if (comand->output != 1)
		close(comand->output);
	if (comand->input != 0)
		close(comand->input);
}

void		simple_execute(t_list *cmds)
{
	t_comand	*comand;

	comand = (t_comand *)(cmds)->content;
	if (comand->comand[0] == NULL)
	{
		close_fd(comand);
		return ;
	}
	if (comand->output < 0 || comand->input < 0)
	{
		ft_print_error("Invalid file descriptor");
		g_process_exit_code = 1;
		return ;
	}
	if (ft_strcmp(comand->comand[0], "cd") == 1)
		g_process_exit_code = ft_cd(comand->comand);
	else if (ft_strcmp(comand->comand[0], "export") == 1)
		export_cond(comand);
	else if (ft_strcmp(comand->comand[0], "unset") == 1)
		unset_cond(comand);
	else if (ft_strcmp(comand->comand[0], "exit") == 1)
		exit_cond(comand);
	else
		simple_child_process(comand);
	close_fd(comand);
}
