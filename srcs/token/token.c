/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:19:48 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:20:05 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include "../libft/libft.h"

t_token	*init_token(char *text, t_tok_type type)
{
	t_token *tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->text = ft_strdup(text);
	if (!tok->text)
		return (NULL);
	tok->type = type;
	return (tok);
}

void	free_token(void *tok)
{
	t_token *t;

	t = (t_token*)tok;
	if (t && t->text)
	{
		free(t->text);
		free(t);
	}
}

void	free_tok_arr(t_token **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free_token(arr[i]);
		i++;
	}
	free(arr);
}

t_token	**lst_to_tok_arr(t_list *head)
{
	int			i;
	t_token		**toks_out;

	toks_out = malloc((ft_lstsize(head) + 1) * sizeof(t_token*));
	if (!toks_out)
		return (NULL);
	i = 0;
	while (head)
	{
		toks_out[i] = head->content;
		i++;
		head = head->next;
	}
	toks_out[i] = NULL;
	return (toks_out);
}

t_bool	is_redir(t_token *t)
{
	if (t->type == GREATER_GREATER || t->type == GREATER || t->type == LESS)
		return (true);
	return (false);
}
