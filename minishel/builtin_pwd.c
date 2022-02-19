/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:13:00 by lmother           #+#    #+#             */
/*   Updated: 2022/02/12 19:50:32 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int pwd(char **args)
{
    char    *pwd;

    pwd = getcwd(NULL, 0);
    if (args)
    {
        if (num_of_args(args) > 1)
            return (p_error("cd", 0, "too many arguments", NULL));
    }
    if (pwd)
    {
        write(1, pwd, ft_strlen(pwd));
        write(1, "\n", 1);
        free(pwd);
        return (0);
    }
    else
        return(p_error("pwd", errno, NULL, NULL));
        
}