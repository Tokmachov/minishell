/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:12:23 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 10:12:27 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_commands.h"
#include "../tokens_src/tokens_src.h"
#include "../expand/expand.h"
#include <errno.h>

static	void	add_arg_to_list(t_list **args_head, char *arg_value)
{
	t_list *new_arg_lst;

	new_arg_lst = ft_lstnew(arg_value);
	if (!new_arg_lst)
	{
		ft_lstclear(args_head, free);
		ft_print_error(strerror(errno));
		return ;
	}
	ft_lstadd_back(args_head, new_arg_lst);
}

static	t_bool	is_cmd_end(t_token *tok)
{
	return (tok->type == SEMICOLON || tok->type == PIPE);
}

void			parse_ags(t_comand *cmd, t_tokens_src src)
{
	t_token	*tok;
	t_list	*args_head;
	char	**cmd_and_args;
	char	*arg_value;

	args_head = NULL;
	while ((tok = next_token(&src)) && !is_cmd_end(tok))
	{
		if (is_redir(tok))
		{
			next_token(&src);
			continue;
		}
		if (tok->type == ARG && (arg_value = expand_arg(tok->text)))
			add_arg_to_list(&args_head, arg_value);
	}
	cmd_and_args = ft_lst_to_arr(args_head);
	cmd->comand = cmd_and_args;
	ft_lstclear(&args_head, NULL);
}
