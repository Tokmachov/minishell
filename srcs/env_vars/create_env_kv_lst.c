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

t_list	*g_env_vars;

static	char	*create_key(char *kv)
{
	int		key_len;
	char	*key;

	key_len = ft_strlen(kv) - ft_strlen(ft_strchr(kv, '='));
	if (!(key = (char *)malloc(sizeof(char) * (key_len + 1))))
	{
		ft_print_error(strerror(errno));
		return (NULL);
	}
	ft_strlcpy(key, kv, key_len + 1);
	return (key);
}

static	char	*create_value(char *kv)
{
	int		len;
	char	*src;
	char	*value;

	src = ft_strchr(kv, '=');
	src++;
	len = ft_strlen(src);
	if (!(value = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_print_error(strerror(errno));
		return (NULL);
	}
	ft_strlcpy(value, src, len + 1);
	return (value);
}

static	t_list	*create_new_kv_lst(char *envp)
{
	t_env	*kv;
	t_list	*new_kv_lst;

	if (!(kv = malloc(sizeof(t_env))))
		return (NULL);
	if (!(kv->value = create_value(envp)))
		return (NULL);
	if (!(kv->key = create_key(envp)))
		return (NULL);
	if (!(new_kv_lst = ft_lstnew(kv)))
		return (NULL);
	return (new_kv_lst);
}

t_list			*ft_create_env_kv_lst(char **envp)
{
	t_list	*env_lst;
	t_list	*new_kv_lst;
	int		i;

	env_lst = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (!(new_kv_lst = create_new_kv_lst(envp[i])))
		{
			ft_lstclear(&env_lst, free_env);
			return (NULL);
		}
		ft_lstadd_back(&env_lst, new_kv_lst);
		i++;
	}
	return (env_lst);
}
