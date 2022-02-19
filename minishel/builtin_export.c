/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:18:22 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 22:00:04 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int print_env(t_env *env)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (tmp->val)
            printf("declare -x %s=\"%s\"\n", tmp->key, tmp->val);
        else
            printf("declare -x %s\n", tmp->key);
        tmp = tmp->next;
    }
    return (0);
}

int check_argv(char *argv, char c)
{
    int i;

    i = -1;
    while (argv[++i] && argv[i] != c)
    {
        if (!ft_isalpha(argv[i]) && i == 0)
            return(p_error("export", 0, "not a valid identifier", argv));
        if (argv[i] != '_' && (!ft_isalpha(argv[i]) && !ft_isdigit(argv[i])))
            return(p_error("export", 0, "not a valid identifier", argv));
    }
    return (0);
}

int add_to_env(t_env *env, char *content)
{
    t_env	*newlst;
    t_env   *tmp;
    t_env   *last;

    tmp = env;
    last = env_lstlast(env);
	newlst = env_lstnew(content);
    if (tmp)
        last->next = newlst;
    else
        return (p_error("export", 0, "Error env is empty", ""));
    return (0);
}

int export(char **argv, t_env *env)
{
    int i;

    i = -1;
    if (argv && !num_of_args(argv))
        return (print_env(env));
    else
    {
        while (argv[++i])
        {
            if (check_argv(argv[i], '='))
                return (1);
            if (!findkey_env(env, argv[i], 1))
                continue;
            else
            {
                if (add_to_env(env, argv[i]))
                    return (1);
            }
        }
        return (0);
    }
    return (1);
}