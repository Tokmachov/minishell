/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_src.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:38:26 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:38:29 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_src.h"
#include <stdlib.h>

static	size_t	tokens_arr_len(t_token **tok)
{
	size_t len;

	len = 0;
	while (tok[len])
		len++;
	return (len);
}

t_tokens_src	init_tokens_src(t_list *tokens)
{
	t_tokens_src	tokens_src;
	t_token			**toks;

	toks = lst_to_tok_arr(tokens);
	tokens_src.curr_index = -1;
	tokens_src.buff_size = tokens_arr_len(toks);
	tokens_src.tokens = toks;
	return (tokens_src);
}

t_token			*next_token(t_tokens_src *src)
{
	src->curr_index++;
	if (src->curr_index >= src->buff_size)
		return (NULL);
	return (src->tokens[src->curr_index]);
}

t_token			*peek_tok(t_tokens_src *src)
{
	int pos;

	pos = src->curr_index;
	pos++;
	if (pos >= src->buff_size)
		return (NULL);
	return (src->tokens[pos]);
	return (NULL);
}

t_tok_type		cur_tok_type(t_tokens_src *tok_src)
{
	return (tok_src->tokens[tok_src->curr_index]->type);
}
