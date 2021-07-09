/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquated_str_exp_and_cpy_to_buf.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:58:40 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:58:48 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../expand/expand.h"
#include "../source/source.h"
#include "../buffer/char_buffer.h"

void	unquated_str_exp_and_cpy_to_buf(t_source *src)
{
	char nc;

	while (((nc = peek_char(src)) && nc != '\'' && nc != '"' && nc != EOF))
		if (nc == '$')
			dollar_exp_and_cpy_to_buf(src, false);
		else if (nc == '\\')
		{
			nc = next_char(src);
			if (peek_char(src) != EOF)
			{
				nc = next_char(src);
				add_to_buf(nc);
			}
			else
				add_to_buf(nc);
		}
		else
		{
			nc = next_char(src);
			add_to_buf(nc);
		}
}
