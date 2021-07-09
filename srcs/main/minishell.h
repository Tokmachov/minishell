/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:03:54 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/28 17:03:57 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lexer/lexer.h"

typedef	enum	e_prompt_type
{
	STD_PROMPT,
	MULTY_LINE_PROMPT,
}				t_prompt_type;

void			print_prompt(t_tokenize_res tokenize_res);

# define EXIT_SUCCESS 0

extern	int		g_process_exit_code;
void			sig_handler(int i);
void			get_input(char **input);
void			parse_and_execute(t_list *toks);

#endif
