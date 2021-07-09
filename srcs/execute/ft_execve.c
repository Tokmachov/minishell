/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:59:07 by hrema             #+#    #+#             */
/*   Updated: 2020/12/02 15:51:28 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_split_path(char *folder, t_comand *comand, char **env)
{
	char	*tmp;
	char	*src;

	tmp = folder;
	if (!(folder = ft_strjoin(folder, "/")))
		ft_exit_with_error("ft_strjoin");
	free(tmp);
	if (!(src = ft_strjoin(folder,
							comand->comand[0])))
		ft_exit_with_error("ft_strjoin");
	free(folder);
	if (execve(src, comand->comand, env) == -1)
	{
		if (errno != ENOENT)
			ft_exit_with_error(strerror(errno));
	}
	free(src);
}

static void	ft_without_path(t_comand *comand, char **env)
{
	char	*src;
	char	**all_folder;
	int		i;

	src = get_var_value("PATH");
	if (src == NULL)
	{
		ft_print_error(strerror(ENOENT));
		exit(127);
	}
	if (!(all_folder = ft_split(src, ':')))
		ft_exit_with_error("ft_split");
	free(src);
	i = 0;
	while (all_folder[i])
	{
		ft_split_path(all_folder[i], comand, env);
		i++;
	}
	free(all_folder);
	ft_print_error("command not found");
	exit(127);
}

static void	check_execve(char *src, char **env, t_comand *comand)
{
	if (execve(src, comand->comand, env) == -1)
	{
		if (errno == ENOENT)
		{
			ft_print_error(strerror(errno));
			exit(127);
		}
		ft_exit_with_error(strerror(errno));
	}
}

static void	relative_path(char **env, t_comand *comand)
{
	char	*src;
	char	*tmp;

	src = get_var_value("PWD");
	tmp = src;
	src = ft_strjoin(src, "/");
	free(tmp);
	tmp = src;
	src = ft_strjoin(src, comand->comand[0]);
	free(tmp);
	check_execve(src, env, comand);
}

void		ft_execve(t_comand *comand)
{
	char	*src;
	char	**env;

	if (comand->input != 0)
		dup2(comand->input, 0);
	if (comand->output != 1)
		dup2(comand->output, 1);
	env = create_export_env_vars_arr(g_env_vars);
	src = comand->comand[0];
	if (src[0] == '/')
		check_execve(src, env, comand);
	else if (ft_strchr(src, '/'))
		relative_path(env, comand);
	else
		ft_without_path(comand, env);
	ft_free_str_arr(env);
}
