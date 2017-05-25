/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 23:11:31 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 23:11:49 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (!*s1 && !*s2)
		return ((char *)s1);
	while (s1[i] && i < (int)n)
	{
		k = i;
		while (s1[i] == s2[j] && s2[j] && i < (int)n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + i - j));
		j = 0;
		i = k;
		i++;
	}
	return (NULL);
}
