/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:26:55 by hrema             #+#    #+#             */
/*   Updated: 2020/11/29 15:16:18 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_malloc(char *string, int len)
{
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		ft_exit_with_error(strerror(errno));
	string[len] = '\0';
	return (string);
}

void		ft_pwd(int output_fd)
{
	char	*curr_dir;
	int		len_curr_dir;

	curr_dir = NULL;
	len_curr_dir = 20;
	curr_dir = ft_malloc(curr_dir, len_curr_dir);
	while (!(getcwd(curr_dir, len_curr_dir)))
	{
		if (errno == ERANGE)
		{
			free(curr_dir);
			curr_dir = NULL;
			len_curr_dir *= 2;
			curr_dir = ft_malloc(curr_dir, len_curr_dir);
		}
		else
			ft_exit_with_error(strerror(errno));
	}
	ft_putendl_fd(curr_dir, output_fd);
	free(curr_dir);
	curr_dir = NULL;
}
