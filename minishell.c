/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:36 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 19:50:46 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"


int main(int argc, char **argv, char **envp)
{
    t_env *env_lst;
    int error_num;

    env_lst = env_to_envlst(envp);
    error_num = 0;
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
            error_num = pwd(&argv[0]);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else if (!ft_strcmp(argv[1], "echo"))
        {
            printf("in ECHO\n\n");
            error_num = echo(argv[2], &argv[2]);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else if (!ft_strcmp(argv[1], "export"))
        {
            printf("in EXPORT\n\n");
            error_num = export(&argv[2], env_lst);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else if (!ft_strcmp(argv[1], "unset"))
        {
            printf("in UNSET\n\n");
            error_num = unset(&argv[2], env_lst);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else if (!ft_strcmp(argv[1], "env"))
        {
            printf("in ENV\n\n");
            error_num = env(&argv[2], env_lst);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else if (!ft_strcmp(argv[1], "exit"))
        {
            printf("in EXIT\n\n");
            error_num = ft_exit(&argv[2], env_lst);
            if (env_lst)
                free_envlst(env_lst->head);
            return (error_num);
        }
        else
            printf("Unknow command\n");
    }
    return (0);
}