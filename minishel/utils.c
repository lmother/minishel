/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:11:56 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 20:04:24 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

int p_error(char *s1, int errnum, char *msg,  char *s2)
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
            write(2, ": `", 3);
            write(2, s2, ft_strlen(s2));
        }
        write(2, "': ", 4);
        write(2, errmes, ft_strlen(errmes));
        write(2, "\n", 1);
    }
    return(1);
}

void free_envlst(t_env *lst)
{
    t_env   *tmp;
    t_env   *node;

    tmp = lst;
    node = NULL;
    while(tmp)
    {
        node = tmp->next;
        free(tmp->key);
        free(tmp->val);
        free(tmp);
        tmp = node;
    }
}

/*how many arguments*/
int num_of_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}