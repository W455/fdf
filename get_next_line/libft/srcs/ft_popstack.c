/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:47:39 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 22:47:41 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_popstack(t_stack **lastin)
{
	int		val;
	t_stack	*tmp;

	if (!lastin)
		return (-1);
	tmp = (*lastin)->prev;
	val = (*lastin)->data;
	free(*lastin);
	*lastin = tmp;
	return (val);
}
