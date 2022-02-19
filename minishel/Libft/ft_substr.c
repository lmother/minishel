/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:22:09 by lmother           #+#    #+#             */
/*   Updated: 2021/05/10 22:48:13 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;
	size_t			l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (len > l || start >= l)
		len = 0;
	substr = (char *) malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len && start < l)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
