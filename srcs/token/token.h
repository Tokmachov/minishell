/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:24:31 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:24:34 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../libft/libft.h"
# include "../token/token.h"

typedef	enum	e_tok_type
{
	ARG,
	SEMICOLON,
	PIPE,
	GREATER,
	GREATER_GREATER,
	LESS,
}				t_tok_type;

typedef	struct	s_token
{
	char		*text;
	t_tok_type	type;
}				t_token;

t_token			*init_token(char *text, t_tok_type type);

void			free_token(void *tok);

void			free_tok_arr(t_token **arr);

t_token			**lst_to_tok_arr(t_list *head);

t_bool			is_redir(t_token *tok);

#endif
