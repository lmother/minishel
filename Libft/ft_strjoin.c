/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:05:16 by lmother           #+#    #+#             */
/*   Updated: 2021/05/15 23:02:01 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s;
	char	*res;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * s + 1);
	if (res == 0)
		return (0);
	s = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[s])
	{
		res[i] = s2[s];
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}
