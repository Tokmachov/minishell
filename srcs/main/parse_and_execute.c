/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:04:05 by sjolynn           #+#    #+#             */
/*   Updated: 2020/12/02 17:13:39 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include "../tokens_src/tokens_src.h"
#include "../parser/parse_commands.h"

void	parse_and_execute(t_list *toks)
{
	t_tokens_src	tok_src;
	t_list			*cmds;

	tok_src = init_tokens_src(toks);
	while ((cmds = parse_commands(&tok_src)))
	{
		ft_comand(cmds);
		ft_lstclear(&cmds, free_cmd);
	}
	free(tok_src.tokens);
}
