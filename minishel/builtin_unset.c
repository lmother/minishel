/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:23:52 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 22:04:39 by lmother          ###   ########.fr       */
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
    printf("elem remove\n");
}

int unset(char **argv, t_env *env)
{
    int i;

    i = -1;
    if (argv)
    {
        while (argv[++i])
        {
            if (check_argv(argv[i], '\0'))
                return (1);
            if (!findkey_env(env, argv[i], 0))
            {
                rm_key(env, argv[i]);
                return (0);
            }
            print_env(env);
        }
    }
    return (0);
}