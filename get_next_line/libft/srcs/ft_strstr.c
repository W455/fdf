/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 23:18:00 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 23:18:05 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (!*s1 && !*s2)
		return ((char *)s1);
	while (s1[i])
	{
		k = i;
		while (s1[i] == s2[j] && s2[j])
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
