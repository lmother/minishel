/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:36 by lmother           #+#    #+#             */
/*   Updated: 2022/04/07 19:49:40 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_readline(t_parser *parser)
{
	char	*str;

	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	rl_on_new_line();
	str = readline("\033[1m\033[149;33mminishell\033[0m> ");
	if (str && !*str)
	{
		free(str);
		return ;
	}
	if (!(str))
	{
		write(1, "exit\n", 6);
		exit(0);
	}
	add_history(str);
	parsing(str, parser);
}

int	main(int argc, char **argv, char **envp)
{
	t_env		*env_lst;
	t_parser	parser;

	(void)argv;
	parser.exit_code = 0;
	if (argc > 1)
		exit (1);
	env_lst = env_to_envlst(envp);
	parser.env = env_lst;
	while (1)
		start_readline(&parser);
	free_envlst(env_lst);
	return (0);
}
