/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:05:16 by lmother           #+#    #+#             */
/*   Updated: 2021/05/05 22:50:52 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*buf;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	new = ft_lstnew(f(tmp->content));
	if (new == NULL)
		ft_lstclear(&new, del);
	buf = new;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		new = ft_lstnew(f(tmp->content));
		if (new == NULL)
			ft_lstclear(&buf, del);
		ft_lstadd_back(&buf, new);
		tmp = tmp->next;
	}
	return (buf);
}
