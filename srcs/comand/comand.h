/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:42:25 by hrema             #+#    #+#             */
/*   Updated: 2020/11/24 15:43:42 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMAND_H
# define COMAND_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_comand
{
	char		**comand;
	int			input;
	int			output;
}				t_comand;

void			free_cmd_arr(t_comand **cmds);

void			free_cmd(void *command);

t_comand		*init_cmd(void);

#endif
