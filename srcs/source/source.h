/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:34:59 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 12:35:01 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# define EOF             (-1)
# define ERRCHAR         ( 0)
# define INIT_SRC_POS    (-1)

typedef	struct	s_source
{
	char	*buffer;
	long	bufsize;
	long	curpos;
}				t_source;

char			next_char(t_source *src);
void			unget_char(t_source *src);
char			peek_char(t_source *src);
void			skip_white_spaces(t_source *src);
char			*peek_word(t_source *src);
t_source		init_char_buff_src(char *input);

#endif
