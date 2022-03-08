/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:56:01 by lmother           #+#    #+#             */
/*   Updated: 2022/03/08 20:47:29 by lmother          ###   ########.fr       */
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
# include <signal.h>
# define CLOSE "\033[0m"
# define BLOD  "\033[1m"
# define COLOR(x,y) "\033["#x";"#y"m"

typedef struct s_env
{
	char			*key;
	char			*val;
	int				index;
	int				flag;
	struct s_env	*next;
}				t_env;

void	rl_replace_line (const char *text, int clear_undo);
int		p_error(char *s1, int errnum, char *msg, char *s2);
void	free_envlst(t_env *lst);
int		num_of_args(char **argv);
int		findkey_env(t_env *env, char *key, int edit);
t_env	*env_to_envlst(char **envp);
t_env	*env_lstlast(t_env *lst);
int		add_pwd_oldpw(t_env *env, char *key, char *val);
t_env	*env_lstnew(char *content);
int		check_argv(char *argv, char c, char *name_bin);
int		print_export(t_env *env, int size);
t_env	*create_first_elment(char *str);
int		sort_export(t_env *env, int size);
int		get_size_envp(t_env *env);
void    handler(int signal);

/*builtins*/
int		cd(char **args, t_env *env);
int		echo(char *option, char **args);
int		pwd(char **args);
int		export(char **argv, t_env *env);
int		unset(char **argv, t_env *env);
int		env(char **argv, t_env *env);
int		ft_exit(char **argv, t_env *env);

#endif