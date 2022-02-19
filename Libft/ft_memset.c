/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:30:43 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 20:14:16 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <strings.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*temp;

	temp = s;
	while (len >= 1)
	{
		temp[len - 1] = (unsigned char) c;
		len--;
	}
	return (s);
}
