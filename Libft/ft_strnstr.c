/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:06:16 by lmother           #+#    #+#             */
/*   Updated: 2021/05/02 20:43:54 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*p;

	i = 0;
	j = ft_strlen(needle);
	if (needle[i] == '\0')
		return ((char *) haystack);
	if (j <= ft_strlen(haystack) && len >= j)
	{
		while (i < len && haystack[i] != '\0')
		{
			if (haystack[i] == needle[0] && j <= len - i)
			{
				p = (const char *) &haystack[i];
				if (ft_strncmp(p, needle, ft_strlen(needle)) == 0)
					return ((char *) &haystack[i]);
			}
			i++;
		}
	}
	return (0);
}
