/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:03:43 by sjolynn           #+#    #+#             */
/*   Updated: 2020/12/02 17:14:16 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minishell.h"
#include "../env_vars/env_vars.h"
#include <signal.h>

int	g_process_exit_code = 0;

int	main(int argc, char *argv[], char **envv)
{
	char			*input;
	t_list			*toks;
	t_tokenize_res	tokenize_res;

	(void)argv;
	(void)argc;
	g_env_vars = ft_create_env_kv_lst(envv);
	toks = NULL;
	tokenize_res = NO_ERROR;
	while (true)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		print_prompt(tokenize_res);
		get_input(&input);
		if ((tokenize_res = tokenize(&toks, input)) != NO_ERROR)
			continue;
		parse_and_execute(toks);
		free(input);
		input = NULL;
		ft_lstclear(&toks, free_token);
	}
	ft_lstclear(&g_env_vars, free_env);
	return (0);
}
