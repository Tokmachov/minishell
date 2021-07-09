/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:04:27 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 16:09:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_lst_to_arr(t_list *head)
{
	int		list_len;
	char	**arr;
	int		i;

	list_len = ft_lstsize(head);
	arr = (char**)malloc((list_len + 1) * sizeof(char*));
	if (!arr)
		return (NULL);
	i = 0;
	while (head)
	{
		arr[i] = head->content;
		i++;
		head = head->next;
	}
	arr[i] = NULL;
	return (arr);
}
