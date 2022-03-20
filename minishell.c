/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:36 by lmother           #+#    #+#             */
/*   Updated: 2022/03/20 18:14:59 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execve_builtin(char **argv, t_env *env_lst)
{
	if (!ft_strcmp(argv[0], "cd"))
	{
		if (num_of_args(argv) > 1)
			return (cd(&argv[1], env_lst));
		else
			cd(NULL, env_lst);
	}
	else if (!ft_strcmp(argv[0], "pwd"))
		return (pwd(&argv[0]));
	else if (!ft_strcmp(argv[0], "echo"))
		return (echo(argv[1], &argv[1]));
	else if (!ft_strcmp(argv[0], "export"))
		return (export(&argv[1], env_lst));
	else if (!ft_strcmp(argv[0], "unset"))
		return (unset(&argv[1], env_lst));
	else if (!ft_strcmp(argv[0], "env"))
		return (env(&argv[1], env_lst));
	else if (!ft_strcmp(argv[0], "exit"))
		return (ft_exit(&argv[1], env_lst));
	return (1);
}

void	start_readline(t_env *env)
{
	char	*str;

	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	rl_on_new_line();
	str = readline(BLOD COLOR(49, 33)"minishell> "CLOSE);
	if (str && !*str)
	{
		free(str);
		return ;
	}
	else if (str == NULL)
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	add_history(str);
	parser(str);
}

int main(int argc, char **argv, char **envp)
{
	t_env *env_lst;
	
	(void)argv;
	if (argc > 1)
		exit (1);
	env_lst = env_to_envlst(envp);
	while (1)
		start_readline(env_lst);
	free_envlst(env_lst);
	return (0);
}