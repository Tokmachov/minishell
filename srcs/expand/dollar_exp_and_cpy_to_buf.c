/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_exp_and_cpy_to_buf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:10:49 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/25 13:10:53 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "expand.h"
#include "../source/source.h"
#include "../buffer/char_buffer.h"
#include "../execute/ft_minishell.h"

static	void	proc_exit_code_exp_and_cpy_to_buf(void)
{
	char	*proc_exit_code_str;
	int		i;

	proc_exit_code_str = ft_itoa(g_process_exit_code);
	i = 0;
	while (proc_exit_code_str[i])
	{
		add_to_buf(proc_exit_code_str[i]);
		i++;
	}
	free(proc_exit_code_str);
}

static	void	move_to_var_name_end(t_source *src)
{
	char nc;

	while ((nc = peek_char(src)) && nc != EOF && is_var_name_char(nc))
		nc = next_char(src);
}

static	void	copy_var_value_to_buff(char *var_val)
{
	int i;

	i = 0;
	while (var_val[i])
	{
		add_to_buf(var_val[i]);
		i++;
	}
}

void			var_value_exp_and_cpy_to_buf(t_source *src)
{
	char *var_name_ptr;
	char *var_name;
	char *var_value;

	var_name_ptr = peek_word(src);
	var_name = get_var_name(var_name_ptr);
	var_value = get_var_value(var_name);
	if (var_value)
		copy_var_value_to_buff(var_value);
	free(var_name);
	free(var_value);
}

void			dollar_exp_and_cpy_to_buf(t_source *src, t_bool is_quated)
{
	char dollar;
	char nc;

	dollar = next_char(src);
	if ((nc = peek_char(src)) && nc != EOF && nc == '?')
	{
		proc_exit_code_exp_and_cpy_to_buf();
		next_char(src);
	}
	else if (!is_quated && nc != EOF && (nc == '\'' || nc == '"'))
		return ;
	else if (nc == EOF || !is_var_name_char(nc))
	{
		add_to_buf(dollar);
		return ;
	}
	else if (ft_isdigit(nc))
		next_char(src);
	else if (is_var_name_char(nc))
	{
		var_value_exp_and_cpy_to_buf(src);
		move_to_var_name_end(src);
	}
}
