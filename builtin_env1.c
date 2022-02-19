/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:45:46 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 18:28:13 by lmother          ###   ########.fr       */
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
            printf("%s=\"%s\"\n", tmp->key, tmp->val);
        else
            printf("%s\n", tmp->key);
        tmp = tmp->next;
    }
    return (0);
}

int env(char **argv, t_env *env)
{
    if (!num_of_args(argv))
        return (print_env(env));
    else
        return (p_error("env", 2, NULL, argv[0]));
}