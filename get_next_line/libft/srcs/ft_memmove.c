/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:47:05 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/14 17:49:35 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	str[n];

	if (n < 134217728)
	{
		ft_memcpy(str, (unsigned char *)s2, n);
		ft_memcpy((unsigned char *)s1, str, n);
		return ((unsigned char *)s1);
	}
	return (NULL);
}
