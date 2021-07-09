/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:00:33 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 15:00:35 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

static t_bool	is_var_name_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char			*get_var_name(char *var_name_ptr)
{
	int		i;
	char	*var_name;

	var_name = ft_strdup(var_name_ptr);
	if (!var_name)
		return (NULL);
	i = 0;
	while (var_name[i] && is_var_name_char(var_name_ptr[i]))
	{
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}
