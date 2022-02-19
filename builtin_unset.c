/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:23:52 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 17:34:57 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

void rm_key(t_env *env, char *argv)
{
    t_env   *tmp;
    t_env   *del;
    t_env   *next;
    char    *spec;

    tmp = env;
    spec = ft_strchr(argv, '=');
    if (spec)
        *spec = '\0';
    del = NULL;
    next = NULL;
    while (tmp && tmp->next && ft_strcmp(tmp->next->key, argv))
        tmp = tmp->next;
    if (tmp)
        del = tmp->next;
    if (del)
        {
            next = del->next;
            if (del->key)
                free(del->key);
            if (del->val)
                free(del->val);
            free(del);
        }
    tmp->next = next;
}

int unset(char **argv, t_env *env)
{
    int i;
    int err_flag;

    i = -1;
    err_flag = 0;
    if (argv)
    {
        while (argv[++i])
        {
            err_flag = check_argv(argv[i], '\0', "unset");
                if (err_flag)
                    continue;
            err_flag = findkey_env(env, argv[i], 0);
            if (!err_flag)
                rm_key(env, argv[i]);
        }
    }
    return (err_flag);
}