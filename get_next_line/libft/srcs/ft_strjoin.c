/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:10:57 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/14 17:00:54 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((sjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i])
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s2) + ft_strlen(s1)))
		sjoin[i++] = s2[j++];
	return (sjoin);
}
