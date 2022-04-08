/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:44:03 by lmother           #+#    #+#             */
/*   Updated: 2022/04/08 18:05:12 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	**copy_envp(char **envp)
{
	int		size;
	char	**copy;

	size = 0;
	while (envp[size])
		size++;
	copy = (char **)malloc(sizeof(char *) * size);
	if (!copy)
		return (NULL);
	size = 0;
	while (envp[size])
	{
		copy[size] = ft_strdup(envp[size]);
		size++;
	}
	return (copy);
}

char	**new_envp(t_env *env)
{
	int		i;
	char	**res;
	t_env	*tmp;
	char	*str;

	i = get_size_envp(env);
	str = NULL;
	tmp = env;
	res = malloc(sizeof(char *) * i);
	if (!res)
		return (NULL);
	i = -1;
	while (tmp)
	{
		res[++i] = ft_strdup(tmp->key);
		str = ft_strdup(res[i]);
		free(res[i]);
		res[i] = ft_strjoin(str, "=");
		free(str);
		str = ft_strdup(res[i]);
		free(res[i]);
		res[i] = ft_strjoin(str, tmp->val);
		free(str);
		tmp = tmp->next;
	}
	return (res);
}
