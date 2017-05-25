/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseconvlo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:17:41 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/12 17:17:42 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BINAIRE 2
#define DECIMAL 10
#define HEXA 16
#define POSITIVE 1
#define NEGATIVE -1

static long		ft_baselong10_2(long nb)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (result <= nb)
		result = ft_power(2, i++);
	i--;
	result = 0;
	while (i >= 0)
	{
		if (nb - ft_power(2, i) >= 0)
		{
			nb -= ft_power(2, i);
			result += ft_power(10, i);
		}
		i--;
	}
	return (result);
}

static long		ft_baselong2_10(long nb)
{
	int		i;
	long	j;
	long	k;

	i = 0;
	j = 0;
	k = nb;
	while (k / 10 > 0)
	{
		if (k % 10 != 0 && k % 10 != 1)
			return (0);
		k /= 10;
		i++;
	}
	while (i >= 0)
	{
		if (nb - ft_power(10, i) >= 0)
		{
			nb -= ft_power(10, i);
			j += ft_power(2, i);
		}
		i--;
	}
	return (j);
}

long			ft_baseconvlo(long nb, unsigned int from, unsigned int to)
{
	int sign;

	sign = 0;
	if (nb >= 0)
		sign = POSITIVE;
	else
	{
		sign = NEGATIVE;
		nb = -nb;
	}
	if (from == DECIMAL && to == BINAIRE)
		return (sign * ft_baselong10_2(nb));
	if (from == BINAIRE && to == DECIMAL)
		return (sign * ft_baselong2_10(nb));
	return (0);
}
