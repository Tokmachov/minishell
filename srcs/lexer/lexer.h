/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:12:00 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 11:12:03 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../source/source.h"
# include "../libft/libft.h"
# include "../token/token.h"
# include "../tokens_src/tokens_src.h"
# include "../buffer/char_buffer.h"

t_token				*get_token(t_source *src);

void				copy_token_to_buf(t_source *src);

t_bool				is_space(char c);

extern	t_tok_type	g_curr_tok_type;

typedef	enum		e_tokenize_res
{
	SYNT_ERROR,
	NEED_INPUT,
	NO_ERROR,
}					t_tokenize_res;

t_tokenize_res		tokenize(t_list **head, char *input);
t_tokenize_res		check_syntax(t_list *tok_head);
void				copy_arg_token_to_buf(t_source *src);

#endif
