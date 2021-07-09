/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:48:53 by hrema             #+#    #+#             */
/*   Updated: 2020/11/25 15:07:30 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_vars.h"

t_list		*g_env_vars;

static void		front_back_split(t_list *source, t_list **front_ref,
									t_list **back_ref)
{
	int		len;
	int		i;
	t_list	*current;
	int		hop_count;

	len = ft_lstsize(source);
	current = source;
	if (len < 2)
	{
		*front_ref = source;
		*back_ref = NULL;
	}
	else
	{
		hop_count = (len - 1) / 2;
		i = 0;
		while (i < hop_count)
		{
			current = current->next;
			i++;
		}
		*front_ref = source;
		*back_ref = current->next;
		current->next = NULL;
	}
}

static t_list	*sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;
	t_env	*env_a;
	t_env	*env_b;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	env_a = (t_env *)a->content;
	env_b = (t_env *)b->content;
	if (ft_strncmp(env_a->key, env_b->key, ft_strlen(env_a->key) + 1) < 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void			sort_env(t_list **env)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *env;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_back_split(head, &a, &b);
	sort_env(&a);
	sort_env(&b);
	*env = sorted_merge(a, b);
}
