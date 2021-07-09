/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:31:13 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 14:46:12 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_env(int output_fd)
{
	char	**env;
	int		i;

	env = create_export_env_vars_arr(g_env_vars);
	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl_fd(env[i], output_fd);
		i++;
	}
}
