/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:13:00 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 18:49:05 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int pwd(char **args)
{
    char    *pwd;

    (void)args; 
    pwd = getcwd(NULL, 0);
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