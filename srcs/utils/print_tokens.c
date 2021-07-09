/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:25:09 by hrema             #+#    #+#             */
/*   Updated: 2020/11/08 17:46:06 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../token/token.h"

static	void	print_tok_type(t_tok_type type)
{
	if (type == ARG)
		ft_putstr_fd("ARG", 1);
	else if (type == GREATER)
		ft_putstr_fd("GREATER", 1);
	else if (type == GREATER_GREATER)
		ft_putstr_fd("GREATER_GREATER", 1);
	else if (type == LESS)
		ft_putstr_fd("LESS", 1);
	else if (type == SEMICOLON)
		ft_putstr_fd("SEMICOLON", 1);
	else if (type == PIPE)
		ft_putstr_fd("PIPE", 1);
	else
		ft_putstr_fd("UNKNOW_TYPE", 1);
}

void			print_token(t_token *tok)
{
	ft_putstr_fd("Tok text: _", 1);
	if (tok->text)
		ft_putendl_fd(tok->text, 1);
	else
		ft_putendl_fd("NULL", 1);
	ft_putstr_fd("Tok type: _", 1);
	print_tok_type(tok->type);
	ft_putstr_fd("\n\n", 1);
}

void			print_tokens(t_list *toks)
{
	t_token *tok;

	while (toks)
	{
		tok = toks->content;
		print_token(tok);
		toks = toks->next;
	}
}
