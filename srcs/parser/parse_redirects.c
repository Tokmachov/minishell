/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:18:57 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 12:18:59 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "parse_commands.h"
#include "../tokens_src/tokens_src.h"
#include "../expand/expand.h"

#include <unistd.h>

static	void	parse_less(t_comand *cmd, t_tokens_src *src)
{
	t_token	*tok;
	char	*file_name;

	tok = next_token(src);
	if (cmd->input != STDIN_FILENO)
		close(cmd->input);
	file_name = expand_arg(tok->text);
	if (file_name && *file_name)
		cmd->input = open(file_name, O_RDONLY);
	else
		cmd->input = -1;
	free(file_name);
}

static	void	parse_greater(t_comand *cmd, t_tokens_src *src)
{
	t_token	*tok;
	char	*file_name;

	tok = next_token(src);
	if (cmd->output != STDOUT_FILENO)
		close(cmd->output);
	file_name = expand_arg(tok->text);
	if (file_name && *file_name)
		cmd->output = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		cmd->output = -1;
	free(file_name);
}

static	void	parse_greater_greater(t_comand *cmd, t_tokens_src *src)
{
	t_token	*tok;
	char	*file_name;

	tok = next_token(src);
	if (cmd->output != STDOUT_FILENO)
		close(cmd->output);
	file_name = expand_arg(tok->text);
	if (file_name && *file_name)
		cmd->output = open(file_name, O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		cmd->output = -1;
	free(file_name);
}

void			parse_redirects(t_comand *cmd, t_tokens_src src)
{
	t_token	*tok;

	while ((tok = next_token(&src)))
	{
		if (tok->type == SEMICOLON || tok->type == PIPE)
			break ;
		if (tok->type == LESS)
			parse_less(cmd, &src);
		else if (tok->type == GREATER)
			parse_greater(cmd, &src);
		else if (tok->type == GREATER_GREATER)
			parse_greater_greater(cmd, &src);
		if (cmd->input < 0 || cmd->output < 0)
			break ;
	}
}
