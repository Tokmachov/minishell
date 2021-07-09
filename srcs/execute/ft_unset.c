/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:33:35 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 10:45:50 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static t_list	*ft_search_elem(char *key)
{
	t_list	*current;
	t_list	*next;
	t_env	*tmp;

	current = g_env_vars;
	next = NULL;
	while (current != NULL)
	{
		tmp = (t_env *)current->content;
		if (ft_strcmp(tmp->key, key) == 1)
		{
			next = current;
			break ;
		}
		current = current->next;
	}
	return (next);
}

static int		conditions(char *key)
{
	char	*error;

	if (key[0] == '-')
	{
		if (!(error = ft_strdup(key)))
			return (ft_return_with_error(strerror(errno), -1));
		if (!(error = ft_strjoin(error, ": not a valid option")))
			return (ft_return_with_error(strerror(errno), -1));
		return (ft_return_with_error(error, 2));
	}
	if (!(is_good_name(key)))
	{
		if (!(error = ft_strdup(key)))
			return (ft_return_with_error(strerror(errno), -1));
		if (!(error = ft_strjoin(error, ": not a valid identifier")))
			return (ft_return_with_error(strerror(errno), -1));
		return (ft_return_with_error(error, 1));
	}
	return (0);
}

int				ft_unset(char *key)
{
	t_list	*current;
	t_list	*next;
	int		res;

	if ((res = conditions(key)) != 0)
		return (res);
	if ((current = g_env_vars) == NULL)
		return (0);
	if ((next = ft_search_elem(key)) == NULL)
		return (0);
	while (current->next != next)
	{
		current = current->next;
	}
	current->next = next->next;
	free_env(next->content);
	free(next);
	return (0);
}
