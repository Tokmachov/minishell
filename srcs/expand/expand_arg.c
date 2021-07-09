/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:52:10 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/30 13:32:47 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/source.h"
#include <stdlib.h>
#include "../execute/ft_minishell.h"
#include "../expand/expand.h"

static	void	expand_and_copy_to_buff(t_source *src, t_bool *has_quates)
{
	char nc;

	nc = peek_char(src);
	*has_quates = false;
	if (nc == '"')
	{
		double_quated_str_exp_and_cpy_to_buf(src);
		*has_quates = true;
	}
	else if (nc == '\'')
	{
		single_quated_str_exp_and_cpy_to_buf(src);
		*has_quates = true;
	}
	else
		unquated_str_exp_and_cpy_to_buf(src);
}

char			*expand_arg(char *arg)
{
	t_source	src;
	char		nc;
	t_bool		has_quates;

	src = init_char_buff_src(arg);
	if (!(init_char_buf()))
		return (NULL);
	while ((nc = peek_char(&src)) != EOF && nc != ERRCHAR)
		expand_and_copy_to_buff(&src, &has_quates);
	g_char_buf[g_char_bufindex] = '\0';
	if (g_char_bufindex == 0 && !has_quates)
		return (NULL);
	return (ft_strdup(g_char_buf));
}
