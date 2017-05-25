/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengthstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:39:53 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 22:39:59 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lengthstack(t_stack *lastin)
{
	int n;

	n = 0;
	while (lastin)
	{
		n++;
		lastin = lastin->prev;
	}
	return (n);
}
