/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 23:07:32 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/13 23:07:33 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = -1;
	if (!(new = ft_strnew((size_t)ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new[i] = (*f)(i, (char)s[i]);
	new[i] = '\0';
	return (new);
}
