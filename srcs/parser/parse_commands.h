/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:20:54 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 12:20:57 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_COMMANDS_H
# define PARSE_COMMANDS_H

# include "../execute/ft_minishell.h"
# include "../token/token.h"
# include "../tokens_src/tokens_src.h"
# include "../comand/comand.h"

t_list		*parse_commands(t_tokens_src *tok_src);

t_list		*get_execute_block(t_tokens_src *tok_src);

t_list		*get_command(t_tokens_src *tok_src);

void		parse_ags(t_comand *cmd, t_tokens_src src);

void		parse_redirects(t_comand *cmd, t_tokens_src src);

#endif
