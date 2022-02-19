/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:49:46 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 20:15:50 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;
	size_t			i;

	tdst = (unsigned char *) dst;
	tsrc = (unsigned char *) src;
	i = 0;
	if (tdst != 0 || tsrc != 0)
	{
		while (i < n)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
