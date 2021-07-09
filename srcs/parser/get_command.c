/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:57:53 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 19:57:56 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_commands.h"
#include "../tokens_src/tokens_src.h"

t_list	*get_command(t_tokens_src *tok_src)
{
	t_comand	*cmd;
	t_list		*cmd_lst;

	if (is_exhasted(tok_src))
		return (NULL);
	cmd = init_cmd();
	parse_ags(cmd, *tok_src);
	parse_redirects(cmd, *tok_src);
	cmd_lst = ft_lstnew(cmd);
	move_to_cmd_end(tok_src);
	return (cmd_lst);
}
