/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_token_to_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:51:13 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 10:51:21 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tok_type	g_curr_tok_type;

static	void		copy_great_great_to_buf(t_source *src)
{
	char nc;

	nc = next_char(src);
	add_to_buf(nc);
	nc = next_char(src);
	add_to_buf(nc);
}

static	t_tok_type	parse_toke_type(char *type)
{
	if ((ft_strncmp(">>", type, 2)) == 0)
		return (GREATER_GREATER);
	else if ((ft_strncmp(">", type, 1)) == 0)
		return (GREATER);
	else if ((ft_strncmp("<", type, 1)) == 0)
		return (LESS);
	else if ((ft_strncmp("|", type, 1)) == 0)
		return (PIPE);
	else if ((ft_strncmp(";", type, 1)) == 0)
		return (SEMICOLON);
	else
		return (ARG);
}

void				copy_token_to_buf(t_source *src)
{
	char nc;
	char *nw;

	nw = peek_word(src);
	nc = peek_char(src);
	if (nw != NULL && ft_strncmp(">>", nw, 2) == 0)
	{
		copy_great_great_to_buf(src);
		g_curr_tok_type = parse_toke_type(nw);
	}
	else if ((ft_strchr("<>|;", nc)))
	{
		nc = next_char(src);
		add_to_buf(nc);
		g_curr_tok_type = parse_toke_type(nw);
	}
	else
	{
		copy_arg_token_to_buf(src);
		g_curr_tok_type = parse_toke_type(nw);
	}
	add_to_buf('\0');
}
