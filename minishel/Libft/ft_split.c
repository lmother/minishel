/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:36:56 by lmother           #+#    #+#             */
/*   Updated: 2021/10/03 15:19:03 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countstr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	void	ft_free(char **str, int n)
{
	while (n >= 0)
	{
		free(str[n]);
		n--;
	}
	free(str);
}

static	char	**ft_splitsub(char const *str, char **res, char ch, int	s)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (n < s)
	{
		while (str[i] == ch)
			i++;
		j = i;
		while (str[j] != ch && str[j] != '\0')
			j++;
		res[n] = ft_substr(str, i, j - i);
		if (res[n] == NULL)
			ft_free(res, n);
		n++;
		i = j;
	}
	res[n] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;

	if (s == NULL)
		return (0);
	size = ft_countstr(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (0);
	return (ft_splitsub(s, res, c, size));
}
