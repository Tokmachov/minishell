/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:58:23 by hrema             #+#    #+#             */
/*   Updated: 2020/12/02 15:34:50 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	*get_elem(void *elem)
{
	return (elem);
}

void		export_print(int output_fd)
{
	t_env	*temp;
	t_list	*head;
	t_list	*env;

	env = ft_lstmap(g_env_vars, get_elem, NULL);
	sort_env(&env);
	head = env;
	while (env != NULL)
	{
		temp = (t_env *)(env)->content;
		if (ft_strcmp(temp->key, "_") != 1)
		{
			ft_putstr_fd("declare -x ", output_fd);
			ft_putstr_fd(temp->key, output_fd);
			if (temp->value != NULL)
			{
				ft_putstr_fd("=\"", output_fd);
				ft_putstr_fd(temp->value, output_fd);
				ft_putstr_fd("\"", output_fd);
			}
			ft_putchar_fd('\n', output_fd);
		}
		env = env->next;
	}
	ft_lstclear(&head, NULL);
}
