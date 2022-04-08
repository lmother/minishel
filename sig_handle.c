/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <lmother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:53:13 by lmother           #+#    #+#             */
/*   Updated: 2022/04/08 15:14:28 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	handler_child(int signal)
{
	if (signal== SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
	}
	else if (signal == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
	}
}
