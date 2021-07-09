/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_quated_str_exp_and_cpy_to_buf.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:05:20 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 15:05:26 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/source.h"
#include "../buffer/char_buffer.h"

void	single_quated_str_exp_and_cpy_to_buf(t_source *src)
{
	char nc;

	nc = next_char(src);
	while ((nc = next_char(src)) && nc != EOF && nc != '\'')
		add_to_buf(nc);
}
