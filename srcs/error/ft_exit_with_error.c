/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:09:00 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 12:09:19 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int			ft_exit_with_error(char *error)
{
	ft_print_error(error);
	exit(EXIT_FAILURE);
}
