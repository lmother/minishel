/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:56:01 by lmother           #+#    #+#             */
/*   Updated: 2022/02/15 22:00:44 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H

# include "./Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>

typedef struct s_env
{
    char            *key;
    char            *val;
    struct s_env    *head;
    struct s_env    *next;
    
}              t_env;

int     p_error(char *s1, int errnum, char *msg,  char *s2);
void    free_envlst(t_env *lst);
int     num_of_args(char **args);
int     findkey_env(t_env *env, char *key, int edit);
t_env   *env_to_envlst(char **envp);
t_env   *env_lstlast(t_env *lst);
int     add_pwd_oldpw(t_env *env, char *key, char *val);
t_env	*env_lstnew(char *content);
int     check_argv(char *argv, char c);
int     print_env(t_env *env);

/*builtins*/
int     cd(char **args, t_env *env);
int     echo(char *option, char **args);
int     pwd(char **args);
int     export(char **argv, t_env *env);
int     unset(char **argv, t_env *env);

#endif