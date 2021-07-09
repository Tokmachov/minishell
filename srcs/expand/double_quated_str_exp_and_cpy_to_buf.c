/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quated_str_exp_and_cpy_to_buf.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:16:28 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 15:16:36 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/source.h"
#include "../libft/libft.h"
#include "../buffer/char_buffer.h"
#include "../expand/expand.h"

void	slashed_str_exp_and_cpy_to_buf(t_source *src)
{
	char nc;

	nc = next_char(src);
	if (ft_strchr("$\'\"\\`", peek_char(src)))
	{
		nc = next_char(src);
		add_to_buf(nc);
	}
	else
		add_to_buf(nc);
}

void	double_quated_str_exp_and_cpy_to_buf(t_source *src)
{
	char nc;

	nc = next_char(src);
	while ((nc = peek_char(src)) && nc != EOF && nc != '"')
	{
		if (nc == '\\')
			slashed_str_exp_and_cpy_to_buf(src);
		else if (nc == '$')
			dollar_exp_and_cpy_to_buf(src, true);
		else
		{
			nc = next_char(src);
			add_to_buf(nc);
		}
	}
	if (nc == '"')
		nc = next_char(src);
}
