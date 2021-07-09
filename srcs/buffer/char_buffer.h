/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_buffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:41:04 by hrema             #+#    #+#             */
/*   Updated: 2020/11/24 15:44:13 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_BUFFER_H
# define CHAR_BUFFER_H

# include <stdlib.h>
# include "../libft/libft.h"

extern char	*g_char_buf;
extern int	g_char_bufsize;
extern int	g_char_bufindex;

void		*init_char_buf(void);

void		add_to_buf(char c);

#endif
