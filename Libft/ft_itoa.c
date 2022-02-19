/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmother <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:13:11 by lmother           #+#    #+#             */
/*   Updated: 2021/05/05 14:14:47 by lmother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_itoa_part(int n, int size, char *res, int d)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n < 0)
		{
			n *= -1;
			res[i] = '-';
			i++;
		}
		res[i] = (n / d) % 10 + 48;
		d /= 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	int		d;
	int		num;
	char	*res;

	i = 1;
	d = 1;
	num = n;
	if (n < 0)
	{
		i++;
		num *= -1;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (num >= 10)
	{
		num /= 10;
		i++;
		d *= 10;
	}
	res = (char *) malloc(sizeof(char) * i + 1);
	if (res == 0)
		return (0);
	return (ft_itoa_part(n, i, res, d));
}
