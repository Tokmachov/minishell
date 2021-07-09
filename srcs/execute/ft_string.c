/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:47:28 by hrema             #+#    #+#             */
/*   Updated: 2020/11/21 15:59:43 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (ft_strlen((char *)ptr_s1) != ft_strlen((char *)ptr_s2))
		return (0);
	while (*ptr_s1 == *ptr_s2 && *ptr_s1 != '\0')
	{
		ptr_s1++;
		ptr_s2++;
	}
	if (*ptr_s1 != *ptr_s2)
		return (0);
	return (1);
}
