/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:18 by hrema             #+#    #+#             */
/*   Updated: 2020/12/02 15:55:29 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	g_flag;

static int	check_cd_export_unset_exit(t_comand *comand, int *res)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(comand->comand[0], "cd") == 1)
	{
		flag = 1;
		*res = ft_cd(comand->comand);
	}
	else if (ft_strcmp(comand->comand[0], "export") == 1)
	{
		flag = 1;
		*res = export_cond(comand);
	}
	else if (ft_strcmp(comand->comand[0], "unset") == 1)
	{
		flag = 1;
		*res = unset_cond(comand);
	}
	else if (ft_strcmp(comand->comand[0], "exit") == 1)
		exit_cond(comand);
	return (flag);
}

static void	hard_parent_procces(pid_t child_pid, t_comand *comand, int *fd,
									int *fd_in)
{
	parent_process(child_pid, comand);
	close(fd[1]);
	if (g_flag == 1)
		close(*fd_in);
	*fd_in = fd[0];
}

static void	hard_child_procces(int *fd_in, int *fd, t_comand *comand,
								t_list *ptr_cmds)
{
	pid_t	child_pid;
	int		res;

	res = 0;
	child_pid = fork();
	if (child_pid == -1)
		ft_print_error(strerror(errno));
	else if (child_pid == 0)
	{
		dup2(*fd_in, 0);
		if (ptr_cmds->next != NULL)
			dup2(fd[1], 1);
		close(fd[0]);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (check_cd_export_unset_exit(comand, &res) == 0)
			check_some_our_comand(comand);
		exit(res);
	}
	else
		hard_parent_procces(child_pid, comand, fd, fd_in);
}

void		hard_execute(t_list *cmds)
{
	t_list		*ptr_cmds;
	int			fd_in;
	int			fd[2];
	t_comand	*comand;

	ptr_cmds = cmds;
	fd_in = 0;
	g_flag = 0;
	while (ptr_cmds != NULL)
	{
		comand = (t_comand *)(ptr_cmds)->content;
		if (comand->output < 0 || comand->input < 0)
			ft_exit_with_error("Invalid file descriptor");
		if (pipe(fd) == -1)
			ft_print_error(strerror(errno));
		hard_child_procces(&fd_in, fd, comand, ptr_cmds);
		if (comand->output != 1)
			close(comand->output);
		if (comand->input != 0)
			close(comand->input);
		ptr_cmds = ptr_cmds->next;
		g_flag = 1;
	}
	close(fd_in);
}
