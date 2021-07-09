/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:31:27 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 12:31:31 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "source.h"
#include "stdlib.h"
#include "../libft/libft.h"

t_source	init_char_buff_src(char *input)
{
	t_source src;

	src.buffer = input;
	src.curpos = -1;
	src.bufsize = ft_strlen(input);
	return (src);
}

void		unget_char(t_source *src)
{
	if (src->curpos < 0)
	{
		return ;
	}
	src->curpos--;
}

char		next_char(t_source *src)
{
	char c;

	if (!src || !src->buffer)
		return (ERRCHAR);
	src->curpos++;
	if (src->curpos >= src->bufsize)
		return (EOF);
	c = src->buffer[src->curpos];
	return (c);
}

char		peek_char(t_source *src)
{
	long pos;

	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	pos = src->curpos;
	pos++;
	if (pos >= src->bufsize)
	{
		return (EOF);
	}
	return (src->buffer[pos]);
}

void		skip_white_spaces(t_source *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return ;
	}
	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
