/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:53:13 by lmother           #+#    #+#             */
/*   Updated: 2022/03/20 17:36:30 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    handler(int signal)
{
    if (signal == SIGINT)
    {
		write(1, "\b\b  \b\b\n", 7);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
    }
}

void    handler_child(int signal)
{
    if (signal == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
	}
	else if (signal == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
	}
}