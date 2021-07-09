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

#include "../env_vars/env_vars.h"

void	print_env_key_vals(t_list *env_kv)
{
	char *key;
	char *val;

	while (env_kv)
	{
		key = ((t_env*)env_kv->content)->key;
		val = ((t_env*)env_kv->content)->value;
		ft_putstr_fd(key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(val, 1);
		env_kv = env_kv->next;
	}
}
