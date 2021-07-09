/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:43:30 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 10:43:38 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "lexer.h"
#include "../buffer/char_buffer.h"

t_token	*get_token(t_source *src)
{
	char nc;

	if (!src || !src->buffer || !src->bufsize)
	{
		errno = ENODATA;
		return (NULL);
	}
	if (!(init_char_buf()))
		return (NULL);
	while ((nc = peek_char(src)) != EOF && nc != ERRCHAR)
	{
		if (is_space(nc))
			skip_white_spaces(src);
		else
		{
			copy_token_to_buf(src);
			break ;
		}
	}
	if (g_char_bufindex == 0)
	{
		return (NULL);
	}
	return (init_token(g_char_buf, g_curr_tok_type));
}
