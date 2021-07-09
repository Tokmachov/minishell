/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:40:41 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/30 12:29:20 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "lexer.h"
#include "../error/error.h"
#include "../main/minishell.h"

t_tokenize_res	tokenize(t_list **head, char *input)
{
	t_token			*token;
	t_list			*new_lst;
	t_source		input_src;
	t_tokenize_res	synt_err;

	input_src = init_char_buff_src(input);
	while ((token = get_token(&input_src)))
	{
		new_lst = ft_lstnew(token);
		if (!new_lst)
			ft_lstclear(head, free_token);
		ft_lstadd_back(head, new_lst);
	}
	synt_err = check_syntax(*head);
	if (synt_err == SYNT_ERROR)
	{
		ft_print_error("minishell: syntax error");
		g_process_exit_code = 2;
		free(input);
		ft_lstclear(head, free_token);
	}
	return (synt_err);
}
