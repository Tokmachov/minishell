/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:44:35 by hrema             #+#    #+#             */
/*   Updated: 2020/12/02 18:22:33 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	free_var(char *str)
{
	free(str);
	str = NULL;
}

static int	ft_set_dir(char *path, char *curr_dir, char *home)
{
	if (chdir(path) == -1)
	{
		free_var(curr_dir);
		free_var(home);
		return (ft_return_with_error(strerror(errno), 1));
	}
	if (!(path = getcwd(NULL, INT_MAX)))
	{
		free_var(curr_dir);
		free(home);
		return (ft_return_with_error(strerror(errno), 1));
	}
	set_var_value("OLDPWD", curr_dir);
	set_var_value("PWD", path);
	free_var(curr_dir);
	free_var(home);
	free_var(path);
	return (0);
}

int			ft_cd(char **comand)
{
	char	*path;
	char	*curr_dir;
	char	*home;
	int		res;

	if (comand[1] && comand[1][1] == '-')
		return (ft_return_with_error("Invalid option", 2));
	path = comand[1];
	curr_dir = get_var_value("PWD");
	home = get_var_value("HOME");
	if (path == NULL)
		path = home;
	else if (ft_strcmp(path, ".") == 1)
		path = curr_dir;
	res = ft_set_dir(path, curr_dir, home);
	return (res);
}
