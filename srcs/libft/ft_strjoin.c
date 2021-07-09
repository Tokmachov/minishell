/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:35:42 by mac               #+#    #+#             */
/*   Updated: 2020/11/21 16:30:06 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *first, char const *second)
{
	size_t	fst_len;
	size_t	scnd_len;
	char	*str_joined;
	size_t	i;

	fst_len = first ? ft_strlen(first) : 0;
	scnd_len = second ? ft_strlen(second) : 0;
	if (!(str_joined = (char*)malloc((fst_len + scnd_len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < fst_len)
	{
		str_joined[i] = first[i];
		i++;
	}
	while (i < fst_len + scnd_len)
	{
		str_joined[i] = second[i - fst_len];
		i++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}
