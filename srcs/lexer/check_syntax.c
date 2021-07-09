/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:08:27 by sjolynn           #+#    #+#             */
/*   Updated: 2020/12/03 14:29:15 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_bool			is_semicolon_synt_error(t_tokens_src *src)
{
	t_token *next_tok;

	if (src->curr_index == 0)
		return (true);
	next_tok = peek_tok(src);
	if (!next_tok)
		return (false);
	if (next_tok->type == SEMICOLON)
		return (true);
	if (next_tok->type == PIPE)
		return (true);
	return (false);
}

static t_tokenize_res	validate_tok_syntax(t_token *curr_tok,
											t_tokens_src *tok_src)
{
	t_token *nt;

	if (is_redir(curr_tok) && (!(nt = peek_tok(tok_src)) || nt->type != ARG))
		return (SYNT_ERROR);
	if (curr_tok->type == SEMICOLON && is_semicolon_synt_error(tok_src))
		return (SYNT_ERROR);
	if (curr_tok->type == PIPE && (tok_src->curr_index == 0))
		return (SYNT_ERROR);
	if (curr_tok->type == PIPE && !(nt = peek_tok(tok_src)))
		return (NEED_INPUT);
	return (NO_ERROR);
}

t_tokenize_res			check_syntax(t_list *tok_head)
{
	t_token			*tok;
	t_tokens_src	tok_src;
	t_tokenize_res	check_res;

	tok_src = init_tokens_src(tok_head);
	check_res = NO_ERROR;
	while ((tok = next_token(&tok_src)))
	{
		if ((check_res = validate_tok_syntax(tok, &tok_src)) != NO_ERROR)
		{
			free(tok_src.tokens);
			return (check_res);
		}
	}
	free(tok_src.tokens);
	return (NO_ERROR);
}
