/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_src.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:39:31 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:39:36 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_SRC_H
# define TOKENS_SRC_H
# include "../libft/libft.h"
# include "../token/token.h"

typedef	struct	s_tokens_src
{
	t_token	**tokens;
	int		curr_index;
	int		buff_size;
}				t_tokens_src;

t_tokens_src	init_tokens_src(t_list *tokens);
t_token			*next_token(t_tokens_src *src);
t_token			*peek_tok(t_tokens_src *src);
t_tok_type		cur_tok_type(t_tokens_src *tok_src);
void			move_to_cmd_end(t_tokens_src *tok_src);
t_bool			is_exhasted(t_tokens_src *src);

#endif
