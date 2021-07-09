/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exhasted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:33:21 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:33:23 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_src.h"

t_bool	is_exhasted(t_tokens_src *src)
{
	t_token *tok;

	if (src->curr_index >= src->buff_size)
		return (true);
	if (src->curr_index >= 0)
	{
		if (cur_tok_type(src) == SEMICOLON && !(tok = peek_tok(src)))
			return (true);
	}
	return (false);
}
