/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:09:54 by lmother           #+#    #+#             */
/*   Updated: 2021/05/06 13:19:42 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*node;

	tmp = *lst;
	node = NULL;
	while (tmp != 0)
	{
		node = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = node;
	}
	*lst = 0;
}
