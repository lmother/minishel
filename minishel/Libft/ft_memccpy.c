/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:56:56 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 13:55:27 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dst != 0 || src != 0)
	{
		while (i < n)
		{
			d[i] = s[i];
			if ((unsigned char) c == d[i])
				return (&d[i + 1]);
			i++;
		}
	}
	return (0);
}
