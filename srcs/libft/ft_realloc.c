/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:20:02 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 16:20:04 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	*ft_realloc(void *old_buff, size_t old_size, size_t new_size)
{
	char *new_buff;

	if (!old_buff)
		return (malloc(new_size * sizeof(char)));
	if (!(new_buff = malloc(new_size * sizeof(char))))
		return (NULL);
	ft_memcpy(new_buff, old_buff, old_size);
	free(old_buff);
	return (new_buff);
}
