/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:44:03 by lmother           #+#    #+#             */
/*   Updated: 2022/04/08 14:15:47 by lmother          ###   ########.fr       */
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
	int		size;
	int		i;
	char	**res;

	size = get_size_envp(env);
	i = 0;
	res = malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_strjoin(res[i], env->key);
		res[i] = ft_strjoin(res[i], "=");
		res[i] = ft_strjoin(res[i], env->val);
		i++;
	}
	return (res);
}
