/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:42:16 by hrema             #+#    #+#             */
/*   Updated: 2020/11/24 15:49:55 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comand.h"

t_comand	*init_cmd(void)
{
	t_comand *cmd;

	cmd = malloc(sizeof(t_comand));
	if (!cmd)
		return (NULL);
	cmd->comand = NULL;
	cmd->input = STDIN_FILENO;
	cmd->output = STDOUT_FILENO;
	return (cmd);
}

void		free_cmd(void *command)
{
	t_comand	*cmd;

	cmd = (t_comand *)command;
	if (cmd->comand)
	{
		ft_free_str_arr(cmd->comand);
	}
	free(cmd);
}

void		free_cmd_arr(t_comand **cmds)
{
	int i;

	i = 0;
	while (cmds[i])
	{
		free_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}
