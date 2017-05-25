/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:48:51 by okrifa            #+#    #+#             */
/*   Updated: 2017/05/24 18:49:18 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(const char a, const char b, int *sign)
{
	if (a == '-' && ft_isdigit(b) == 1)
	{
		*sign = -1;
		return (1);
	}
	if (a == '+' && ft_isdigit(b) == 1)
		return (1);
	if (ft_isdigit(a) == 1)
		return (2);
	return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (ft_sign(str[i], str[i + 1], &sign) == 0)
		return (0);
	if (ft_sign(str[i], str[i + 1], &sign) == 1)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		res = res * 10 + str[i++] - '0';
	str += i;		
	return (sign * res);
}
