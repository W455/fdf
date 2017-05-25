/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:54:52 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 22:55:06 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_pushstack(t_stack **lastin, int val)
{
	t_stack *element;

	if ((element = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	element->data = val;
	element->prev = *lastin;
	*lastin = element;
	return (*lastin);
}
