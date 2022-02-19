/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:31:46 by lmother           #+#    #+#             */
/*   Updated: 2021/05/07 12:03:31 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_fset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	k;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	k = ft_strlen(s1);
	while (ft_fset(set, s1[i]) == 1)
		i++;
	if (i == k)
		return (ft_substr(s1, i, k - i));
	while (ft_fset(set, s1[k - 1]) == 1)
		k--;
	return (ft_substr(s1, i, k - i));
}
