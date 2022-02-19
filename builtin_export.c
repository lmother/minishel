/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:18:22 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 17:47:20 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int print_export(t_env *env)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (*tmp->key == '_' && ft_strlen(tmp->key) == 1)
        {
            tmp = tmp->next;
            continue;
        }
        if (tmp->val)
            printf("declare -x %s=\"%s\"\n", tmp->key, tmp->val);
        else
            printf("declare -x %s\n", tmp->key);
        tmp = tmp->next;
    }
    return (0);
}

int check_argv(char *argv, char c, char *name_bin)
{
    int i;
    int err_flag;

    i = -1;
    err_flag = 0;
    while (argv[++i] && argv[i] != c)
    {
        if (!ft_isalpha(argv[i]) && i == 0)
            err_flag = p_error(name_bin, 0, "not a valid identifier", argv);
        else if (!ft_isalpha(argv[i]) && !ft_isdigit(argv[i]))
            err_flag = p_error(name_bin, 0, "not a valid identifier", argv);
    }
    return (err_flag);
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
    int err_flag;

    i = -1;
    err_flag = 0;
    if (argv && !num_of_args(argv))
        return (print_export(env));
    else
    {
        while (argv[++i])
        {
            err_flag = check_argv(argv[i], '=', "export");
            if (err_flag || !findkey_env(env, argv[i], 1))
                continue;
            else
                err_flag = add_to_env(env, argv[i]);
        }
        return (err_flag);
    }
    return (1);
}