/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:57:56 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 22:58:08 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_squareroot(unsigned int n)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 1;
	j = 0;
	k = 0;
	if (n == 1)
		return (1);
	if (n == 0)
		return (0);
	while (k <= n)
	{
		if (k == n)
			return (j);
		k += i;
		i += 2;
		j++;
	}
	return (0);
}
