/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:06:37 by hrema             #+#    #+#             */
/*   Updated: 2020/11/24 15:53:41 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_vars.h"

char	*create_kv_str(t_env *env)
{
	char *temp;
	char *kv_str;

	temp = ft_strjoin(env->key, "=");
	if (!temp)
		return (NULL);
	kv_str = ft_strjoin(temp, env->value);
	free(temp);
	return (kv_str);
}

int		count_uninit_vars(t_list *env_kv_lst)
{
	int		count;
	t_env	*env_kv;

	count = 0;
	while (env_kv_lst)
	{
		env_kv = (t_env*)env_kv_lst->content;
		if (env_kv->value)
			count++;
		env_kv_lst = env_kv_lst->next;
	}
	return (count);
}

char	**create_export_env_vars_arr(t_list *env_kv_lst)
{
	char	**arr;
	t_env	*env_kv;
	int		i;

	if (!(arr = malloc((count_uninit_vars(env_kv_lst) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (env_kv_lst)
	{
		env_kv = (t_env*)env_kv_lst->content;
		if (env_kv->value)
		{
			arr[i] = create_kv_str(env_kv);
			if (!arr[i])
			{
				ft_free_str_arr(arr);
				return (NULL);
			}
			i++;
		}
		env_kv_lst = env_kv_lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
