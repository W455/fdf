/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:46:28 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 22:46:37 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char *pstr1;
	unsigned char *pstr2;

	pstr1 = (unsigned char*)str1;
	pstr2 = (unsigned char*)str2;
	while (n-- > 0)
		pstr1[n] = pstr2[n];
	return (str1);
}
