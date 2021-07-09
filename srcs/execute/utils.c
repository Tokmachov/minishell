/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:53:57 by hrema             #+#    #+#             */
/*   Updated: 2020/12/03 14:38:51 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int			is_good_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (!(ft_isalpha(str[i])) || str[i] == '='))
			return (0);
		if (!ft_isalpha(str[i]))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static void	sig_handler2(int i)
{
	if (i == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 1);
	}
	else if (i == SIGINT)
	{
		ft_putstr_fd("\n", 1);
	}
}

void		parent_process(pid_t child_pid, t_comand *comand)
{
	int	stat_loc;

	signal(SIGINT, sig_handler2);
	signal(SIGQUIT, sig_handler2);
	if (waitpid(child_pid, &stat_loc, WUNTRACED | WCONTINUED) == -1)
		ft_print_error(strerror(errno));
	if (WIFEXITED(stat_loc))
		g_process_exit_code = WEXITSTATUS(stat_loc);
	else if (WIFSIGNALED(stat_loc))
		g_process_exit_code = 128 + WTERMSIG(stat_loc);
	else if (WIFSTOPPED(stat_loc))
		g_process_exit_code = WSTOPSIG(stat_loc);
	else if (WIFCONTINUED(stat_loc))
		ft_putendl_fd("continued", comand->output);
}

void		check_some_our_comand(t_comand *comand)
{
	if (ft_strcmp(comand->comand[0], "echo") == 1)
		ft_echo(comand->comand, comand->output);
	else if (ft_strcmp(comand->comand[0], "pwd") == 1)
		pwd_cond(comand);
	else if (ft_strcmp(comand->comand[0], "env") == 1)
	{
		if (comand->comand[1] != NULL)
			ft_exit_with_error("Env error: odd arguments");
		ft_env(comand->output);
	}
	else
		ft_execve(comand);
}
