/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 23:21:22 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 23:21:24 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_viewstack(t_stack *lastin)
{
	while (lastin)
	{
		ft_putnbr(lastin->data);
		ft_putchar('\n');
		lastin = lastin->prev;
	}
}
