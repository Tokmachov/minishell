/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:13:07 by sjolynn           #+#    #+#             */
/*   Updated: 2020/12/01 13:30:56 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_commands.h"
#include "../expand/expand.h"

static	t_bool	did_reach_cmd_end(t_tokens_src *src)
{
	t_tok_type type;

	if (src->curr_index >= src->buff_size)
		return (true);
	type = cur_tok_type(src);
	if (type == SEMICOLON)
		return (true);
	return (false);
}

t_list			*parse_commands(t_tokens_src *tok_src)
{
	t_list	*cmd_lst_head;
	t_list	*cmd_lst_new;

	cmd_lst_head = NULL;
	while ((cmd_lst_new = get_command(tok_src)))
	{
		ft_lstadd_back(&cmd_lst_head, cmd_lst_new);
		if (did_reach_cmd_end(tok_src))
			break ;
	}
	return (cmd_lst_head);
}
