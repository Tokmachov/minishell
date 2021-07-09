/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:06:37 by hrema             #+#    #+#             */
/*   Updated: 2020/12/02 17:09:21 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_comand(t_list *cmds)
{
	if (ft_lstsize(cmds) == 1)
		simple_execute(cmds);
	else
		hard_execute(cmds);
}
