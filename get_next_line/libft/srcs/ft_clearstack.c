/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:18:04 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/12 17:18:05 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clearstack(t_stack **lastin)
{
	t_stack	*tmp;

	while (*lastin)
	{
		tmp = (*lastin)->prev;
		free(*lastin);
		*lastin = tmp;
	}
}
