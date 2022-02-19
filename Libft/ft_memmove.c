/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:20:56 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 20:20:00 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dst != 0 || src != 0)
	{
		if (d <= s)
		{
			ft_memcpy(d, s, len);
		}
		else
		{
			while (len > 0)
			{
				d[len - 1] = s[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
