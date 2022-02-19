/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:39:50 by lmother           #+#    #+#             */
/*   Updated: 2021/05/06 19:33:50 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	obj = 0;
	obj = malloc(count * size);
	if (obj == 0)
		return (obj);
	ft_bzero(obj, count * size);
	return (obj);
}
