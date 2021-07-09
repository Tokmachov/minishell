/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_kv_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:06:37 by hrema             #+#    #+#             */
/*   Updated: 2020/11/30 12:10:43 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_vars.h"
#include "../execute/ft_minishell.h"

t_list	*g_env_vars;

char	*get_var_value(char *var_name)
{
	t_list	*kv_lst_head;
	t_list	*current;
	char	*key_tmp;
	char	*val_tmp;

	val_tmp = NULL;
	kv_lst_head = g_env_vars;
	current = kv_lst_head;
	while (current)
	{
		key_tmp = ((t_env*)current->content)->key;
		if (ft_strncmp(key_tmp, var_name, (ft_strlen(var_name) + 1)) == 0)
		{
			if (((t_env*)current->content)->value)
				val_tmp = ft_strdup(((t_env*)current->content)->value);
			break ;
		}
		current = current->next;
	}
	return (val_tmp);
}

void	free_env(void *env)
{
	t_env	*env_tmp;

	env_tmp = env;
	free(env_tmp->key);
	free(env_tmp->value);
	free(env_tmp);
}

void	set_var_value(char *key, char *value)
{
	t_list	*env;
	t_env	*kv;

	env = g_env_vars;
	while (env)
	{
		kv = (t_env *)env->content;
		if (ft_strcmp(kv->key, key) == 1)
		{
			if (kv->value)
				free(kv->value);
			kv->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
}
