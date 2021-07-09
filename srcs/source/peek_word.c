/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:30:35 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 12:30:39 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "source.h"
#include <stdio.h>

char		*peek_word(t_source *src)
{
	long pos;

	pos = src->curpos;
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (NULL);
	}
	pos++;
	if (pos >= src->bufsize)
	{
		return (NULL);
	}
	return (src->buffer + pos);
}
