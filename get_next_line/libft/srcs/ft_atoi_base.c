/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 00:20:21 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/12 17:31:54 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TRUE 1
#define FALSE 0

static int		ft_sign(char s, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == s)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 31)
			return (FALSE);
		while (j < i)
			if (base[i] == base[j++])
				return (FALSE);
		j = 0;
		i++;
	}
	return (i >= 2 ? TRUE : FALSE);
}

static int		ft_len(char *str, char *base)
{
	int i;

	i = 0;
	while (str[i] && ft_sign(str[i], base))
		i++;
	return (i);
}

static int		ft_po(int nb, int power)
{
	int res;

	res = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power > 1)
		res *= ft_po(nb, power - 1);
	return (res);
}

int				ft_atoi_base(char *s, char *ba)
{
	int res;
	int sign;
	int i;
	int j;

	i = 0;
	j = 0;
	res = 0;
	sign = 1;
	if (ft_check_base(ba) == 0)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\r'
			|| *s == '\t' || *s == '\v' || *s == '\f')
		s++;
	sign = (s[i] == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_sign(s[i], ba) == TRUE && s[i])
	{
		while (s[i] != ba[j])
			j++;
		res = res + j++ * ft_po(ft_len(ba, ba), ft_len(s, ba) - i++ - 1);
		j = 0;
	}
	return (res * sign);
}
