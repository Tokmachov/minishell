/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:04:43 by sjolynn           #+#    #+#             */
/*   Updated: 2020/11/28 17:04:47 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include "../lexer/lexer.h"
#include <unistd.h>

void	sig_handler(int i)
{
	if (i == SIGINT)
	{
		ft_putstr_fd("\b\b  \n", STDIN_FILENO);
		print_prompt(NO_ERROR);
	}
	else if (i == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \b\b", STDIN_FILENO);
	}
}
