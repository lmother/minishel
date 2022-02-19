/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:36 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 21:42:50 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"


int main(int argc, char **argv, char **envp)
{
    t_env *env_lst;

    env_lst = env_to_envlst(envp);
    if (argc > 1)
    {
        if (!ft_strcmp(argv[1], "cd"))
        {
            if (argc > 2)
            {
                printf("in CD\n\n");
                return (cd(&argv[1], env_lst));
            }
            else
                cd(NULL, env_lst);
        }
        else if (!ft_strcmp(argv[1], "pwd"))
        {
            printf("in PWD\n\n");
            return (pwd(&argv[0]));
        }
        else if (!ft_strcmp(argv[1], "echo"))
        {
            printf("in ECHO\n\n");
            return (echo(argv[2], &argv[2]));
        }
        else if (!ft_strcmp(argv[1], "export"))
        {
            printf("in EXPORT\n\n");
            return (export(&argv[2], env_lst));
        }
        else if (!ft_strcmp(argv[1], "unset"))
        {
            printf("in UNSET\n\n");
            return (unset(&argv[2], env_lst));
        }
    }
    if (env_lst)
        free_envlst(env_lst->head);
    return (0);
}