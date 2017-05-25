/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:42:22 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/12 17:24:32 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	int sign;

	if (nb >= 13 || nb <= -13)
		return (0);
	sign = (nb >= 0) ? 1 : -1;
	nb = (nb >= 0) ? nb : -nb;
	if (nb == 0)
		return (1);
	if (nb >= 1)
		return (sign * nb * ft_factorial(nb - 1));
	return (0);
}
