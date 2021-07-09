/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:17:12 by hrema             #+#    #+#             */
/*   Updated: 2020/12/01 13:35:59 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	is_var(char *var_name)
{
	t_list	*env;
	t_env	*temp;

	env = g_env_vars;
	while (env != NULL)
	{
		temp = (t_env *)env->content;
		if (ft_strcmp(temp->key, var_name) == 1)
			return (1);
		env = env->next;
	}
	return (0);
}

static int	get_kv_value(char *key_value, t_env **kv, int *len)
{
	char	*src;

	if (!(src = ft_strchr(key_value, '=')))
	{
		(*kv)->value = NULL;
		*len = ft_strlen(key_value);
	}
	else
	{
		src++;
		*len = ft_strlen(src);
		if (!((*kv)->value = (char *)malloc(sizeof(char) * (*len + 1))))
			return (ft_return_with_error(strerror(errno), -1));
		ft_strlcpy((*kv)->value, src, *len + 1);
		*len = ft_strlen(key_value) - *len - 1;
	}
	return (0);
}

static int	get_kv_key(char *key_value, t_env **kv, int len)
{
	char	*error;

	if (!((*kv)->key = (char *)malloc(sizeof(char) * (len + 1))))
		return (ft_return_with_error(strerror(errno), -1));
	if (key_value[0] == '=')
		ft_strlcpy((*kv)->key, key_value, ft_strlen(key_value) + 1);
	else
		ft_strlcpy((*kv)->key, key_value, len + 1);
	if (!is_good_name((*kv)->key))
	{
		if (!(error = ft_strdup((*kv)->key)))
			return (ft_return_with_error(strerror(errno), -1));
		if (!(error = ft_strjoin(error, ": not a valid identifier")))
			return (ft_return_with_error(strerror(errno), -1));
		return (ft_return_with_error(error, 1));
	}
	return (0);
}

static int	ft_get_kv(t_env *kv)
{
	t_list	*new;

	if (is_var(kv->key))
	{
		if (kv->value == NULL)
			return (0);
		set_var_value(kv->key, kv->value);
		free_env(kv);
	}
	else
	{
		if (!(new = ft_lstnew((void *)kv)))
			return (ft_return_with_error(strerror(errno), -1));
		ft_lstadd_back(&g_env_vars, new);
	}
	return (0);
}

int			ft_export(char *key_value)
{
	int		len;
	t_env	*kv;
	int		res;
	char	*error;

	len = 0;
	if (key_value[0] == '-')
	{
		if (!(error = ft_strdup(key_value)))
			return (ft_return_with_error(strerror(errno), -1));
		if (!(error = ft_strjoin(error, ": not a valid option")))
			return (ft_return_with_error(strerror(errno), -1));
		return (ft_return_with_error(error, 2));
	}
	if (!(kv = (t_env *)malloc(sizeof(t_env))))
		return (ft_return_with_error(strerror(errno), -1));
	if ((res = get_kv_value(key_value, &kv, &len)) == -1)
		return (-1);
	if ((res = get_kv_key(key_value, &kv, len)) != 0)
		return (res);
	if ((res = ft_get_kv(kv)) == -1)
		return (res);
	return (0);
}
