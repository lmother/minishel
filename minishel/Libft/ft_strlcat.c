/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:42:01 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 19:33:33 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s;

	j = ft_strlen(dst);
	i = j;
	s = 0;
	if (dstsize == 0)
		return (0 + ft_strlen(src));
	while (i < dstsize - 1 && src[s])
	{
		dst[i] = src[s];
		i++;
		s++;
	}
	if (j < dstsize)
		dst[i] = '\0';
	if (j >= dstsize)
		j = dstsize;
	return (j + ft_strlen(src));
}
