/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:02:49 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 15:52:45 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"
# include "../error/error.h"
# include "../comand/comand.h"
# include "../env_vars/env_vars.h"
# include "../main/minishell.h"
# include <signal.h>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_pwd(int output_fd);
int		ft_exit_with_error(char *error);
int		ft_cd(char **comand);
void	ft_echo(char **comand, int fd);
void	ft_comand(t_list *cmds);
void	set_var_value(char *key, char *value);
void	ft_env(int output_fd);
int		ft_unset(char *key);
int		is_good_name(char *str);
int		ft_export(char *key_value);
int		ft_return_with_error(char *error, int res);
void	export_print(int output_fd);
int		export_cond(t_comand *comand);
int		unset_cond(t_comand *comand);
void	exit_cond(t_comand *comand);
void	pwd_cond(t_comand *comand);
void	ft_execve(t_comand *comand);
void	simple_execute(t_list *cmds);
void	check_some_our_comand(t_comand *comand);
void	parent_process(pid_t child_pid, t_comand *comand);
void	hard_execute(t_list *cmds);

#endif
