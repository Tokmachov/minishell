/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:44:22 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 14:44:32 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../comand/comand.h"
# include "../token/token.h"

void	print_cmd(t_comand *cmd);

void	print_token(t_token *tok);

void	print_tokens(t_list *toks);

void	print_env_key_vals(t_list *env_kv);

#endif
