/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:04:22 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/28 17:04:37 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minishell.h"

void	print_prompt(t_tokenize_res tokenize_res)
{
	if (tokenize_res == NO_ERROR)
		ft_putstr_fd("minishell $ ", 2);
	else if (tokenize_res == NEED_INPUT)
		ft_putstr_fd("> ", 2);
	else
		ft_putstr_fd("minishell $ ", 2);
}
