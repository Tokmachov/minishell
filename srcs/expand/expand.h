/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:03:22 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/26 15:03:25 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../token/token.h"
# include "../source/source.h"

char			*expand_arg(char *arg);

void			single_quated_str_exp_and_cpy_to_buf(t_source *src);

void			unquated_str_exp_and_cpy_to_buf(t_source *src);

void			dollar_exp_and_cpy_to_buf(t_source *src, t_bool is_quated);

char			*get_var_name(char *var_name_ptr);

t_bool			is_var_name_char(char c);

void			double_quated_str_exp_and_cpy_to_buf(t_source *src);

#endif
