/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:02:49 by hrema             #+#    #+#             */
/*   Updated: 2020/11/27 12:10:58 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_H
# define ENV_VARS_H

# include <errno.h>
# include "../libft/libft.h"
# include "../error/error.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

extern	t_list	*g_env_vars;

t_list			*ft_create_env_kv_lst(char **envp);

char			*get_var_value(char *var_name);

void			free_env(void *env);

void			sort_env(t_list **env);

char			**create_export_env_vars_arr(t_list *env_kv_lst);
void			set_var_value(char *key, char *value);

#endif
