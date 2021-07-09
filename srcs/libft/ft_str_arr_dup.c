/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:04:27 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 16:09:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_arr_dup(char **arr)
{
	int		i;
	size_t	arr_len;
	char	**arr_copy;

	if (!arr)
		return (NULL);
	i = 0;
	arr_len = ft_str_arr_len(arr);
	arr_copy = malloc((arr_len + 1) * sizeof(char*));
	if (!arr_copy)
		return (NULL);
	while (arr[i])
	{
		arr_copy[i] = ft_strdup(arr[i]);
		if (!arr_copy)
		{
			ft_free_str_arr(arr_copy);
			return (NULL);
		}
		i++;
	}
	arr_copy[i] = NULL;
	return (arr_copy);
}
