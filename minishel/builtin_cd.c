/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:20:21 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 18:39:07 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int   add_pwd_oldpw(t_env *env, char *key, char *val)
{
    t_env	*newlst;
    t_env   *tmp;
    t_env   *last;

    tmp = env;
    last = env_lstlast(env);
	newlst = malloc(sizeof(t_env));
	if (!newlst)
		return (1);
    if (tmp != NULL && tmp->next)
    {
        while (tmp->next->next != NULL)
            tmp = tmp->next;
    }
    newlst->key = ft_strdup(key);
    newlst->val = ft_strdup(val);
    newlst->next = last;
    tmp->next = newlst;
    return (0);
}

/*change key in env_lst*/
int change_key(t_env *env, char *key, char *val)
{
    t_env   *tmp;

    tmp = env;
    if (!findkey_env(env, key, 0))
    {
        while (tmp)
        {
            if(!ft_strcmp(tmp->key, key))
            {
                free(tmp->val);
                tmp->val = ft_strdup(val);
                return (0);
            }
            tmp = tmp->next;
        }
    }
    if (!ft_strcmp("PWD", key))
        add_pwd_oldpw(env, key, val);
    if (!ft_strcmp("OLDPWD", key))
        add_pwd_oldpw(env, key, val);
    return (1);
}

int ch_dir(char *path, t_env *env)
{
    change_key(env, "OLDPWD", getcwd(NULL, 0));
    if(!chdir(path))
        change_key(env, "PWD", getcwd(NULL, 0));
    else
        return (p_error("cd", errno, NULL, path));
    return (0);
}

int cd(char **args, t_env *env)
{
    char    *key;

    key = NULL;
    if (!args)
    {
        key = getenv("HOME");
        if (!key)
            return (0);
        else
            return (ch_dir(key, env));
    }
    else if (num_of_args(args) > 1)
        return (p_error("cd", 0, "too many arguments", NULL));
    else
        return (ch_dir(args[1], env));
    return (1);
}