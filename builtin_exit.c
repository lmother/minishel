/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:24:51 by lmother           #+#    #+#             */
/*   Updated: 2022/02/19 20:51:31 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

static int p_error_exit(char *s1, int errnum, char *msg,  char *s2)
{
    char    *errmes;

    if (s1)
    {
        if (!msg)
            errmes = strerror(errnum);
        else
            errmes = msg;
        write(2, s1, ft_strlen(s1));
        if (s2)
        {
            write(2, ": ", 3);
            write(2, s2, ft_strlen(s2));
        }
        write(2, ": ", 3);
        write(2, errmes, ft_strlen(errmes));
        write(2, "\n", 1);
    }
    return(1);
}

int check_argv_exit(char *argv)
{
    int i;

    i = -1;
    while (argv && argv[++i])
    {
        if (!ft_isalnum(argv[i]))
        {
            write(1, "exit\n", 5);
            return (p_error_exit("exit", 0, "numeric argument required", argv));
        }
    }
    return (0);
}

int ft_exit(char **argv, t_env *env)
{
    (void)env;
    if (num_of_args(argv) > 0)
    {
        if (check_argv_exit(argv[0]))
            exit (255);
        else if (num_of_args(argv) == 1)
        {
            write(1, "exit\n", 5);
            exit (ft_atoi(argv[0]));
        }
        else
        {
            write(1, "exit\n", 5);
            return (p_error_exit("exit", 0, "too many arguments", NULL));
        }
    }
    else
    {
        write(1, "exit\n", 5);
        exit (-1);
    }
}