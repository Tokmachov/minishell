/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:37:16 by hrema             #+#    #+#             */
/*   Updated: 2020/11/24 16:25:12 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

char	*g_char_buf = NULL;
int		g_char_bufsize = 0;
int		g_char_bufindex = -1;

void	add_to_buf(char c)
{
	char	*tmp;

	g_char_buf[g_char_bufindex] = c;
	g_char_bufindex++;
	if (g_char_bufindex >= g_char_bufsize)
	{
		tmp = ft_realloc(g_char_buf, g_char_bufsize, g_char_bufsize * 2);
		if (!tmp)
			return ;
		g_char_buf = tmp;
		g_char_bufsize *= 2;
	}
}

void	*init_char_buf(void)
{
	g_char_bufsize = 1024;
	g_char_bufindex = 0;
	if (!g_char_buf)
		g_char_buf = malloc(g_char_bufsize * sizeof(char));
	if (!g_char_buf)
		return (NULL);
	g_char_buf[g_char_bufindex] = '\0';
	return (g_char_buf);
}
