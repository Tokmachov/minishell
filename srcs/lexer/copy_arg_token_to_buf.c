/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_arg_token_to_buf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:56:57 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/27 16:08:32 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../libft/libft.h"

#define IGNORE_SLASH_REMOVAL_CHARS "'\"$"

static	t_bool	is_arg_end(char c)
{
	return (ft_strchr("<>|;", c) || is_space(c) || c == EOF);
}

void			copy_slashed_char_to_buff(t_source *src)
{
	char nc;

	nc = next_char(src);
	add_to_buf(nc);
	if ((nc = peek_char(src)) != EOF)
	{
		nc = next_char(src);
		add_to_buf(nc);
	}
}

void			copy_double_quated_arg(t_source *src)
{
	char nc;

	nc = next_char(src);
	add_to_buf(nc);
	while ((nc = next_char(src)) && nc != EOF)
	{
		add_to_buf(nc);
		if (nc == '"' && src->buffer[src->curpos - 1] != '\\')
			break ;
	}
}

void			copy_single_quated_arg(t_source *src)
{
	char nc;

	nc = next_char(src);
	add_to_buf(nc);
	while ((nc = next_char(src)) && nc != EOF && nc != '\'')
		add_to_buf(nc);
	if (nc == '\'')
		add_to_buf(nc);
}

void			copy_arg_token_to_buf(t_source *src)
{
	char nc;

	while ((nc = peek_char(src)) && !is_arg_end(nc))
	{
		if (nc == '\'')
			copy_single_quated_arg(src);
		else if (nc == '"')
			copy_double_quated_arg(src);
		else if (nc == '\\')
			copy_slashed_char_to_buff(src);
		else
		{
			nc = next_char(src);
			add_to_buf(nc);
		}
	}
}
