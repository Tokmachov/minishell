/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:02:53 by sjolynn           #+#    #+#             */
/*   Updated: 2020/12/03 14:27:47 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>

static void	free_and_assign_null(char **str)
{
	free(*str);
	*str = NULL;
}

void		get_input(char **input)
{
	static	char	*cash;
	int				gnl_result;
	char			*line;
	char			*tmp;

	while ((gnl_result = get_next_line(0, &line)) != 1)
	{
		if (gnl_result == 0 && *line != '\0')
		{
			tmp = cash;
			cash = ft_strjoin(cash, line);
			free(tmp);
			free(line);
			continue;
		}
		else if (gnl_result == 0 && *line == '\0' && !cash)
			exit(EXIT_SUCCESS);
		else
			free(line);
	}
	*input = ft_strjoin(cash, line);
	free_and_assign_null(&line);
	free_and_assign_null(&cash);
}
