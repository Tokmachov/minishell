/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_cmd_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:34:18 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:34:23 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_src.h"

void	move_to_cmd_end(t_tokens_src *tok_src)
{
	t_token *tok;

	while ((tok = next_token(tok_src)))
	{
		if (tok->type == SEMICOLON || tok->type == PIPE)
			break ;
	}
}
