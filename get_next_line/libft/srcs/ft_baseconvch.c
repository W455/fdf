/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseconvch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:17:31 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/12 17:17:32 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BINAIRE 2
#define DECIMAL 10
#define HEXA 16
#define POSITIVE 1
#define NEGATIVE -1

static char		*ft_basechar10_2(char *nb)
{
	int		tab[3];
	char	*result;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = ft_atoi(nb);
	while (tab[1] <= tab[2] && tab[0] < 31)
		tab[1] = ft_power(2, tab[0]++);
	if ((result = ft_strnew((size_t)(tab[0] + 1))) == NULL)
		return (NULL);
	tab[1] = tab[0];
	while (tab[0] >= 0)
	{
		if (tab[2] - ft_power(2, tab[0]) >= 0)
		{
			tab[2] -= ft_power(2, tab[0]);
			*result = '1';
		}
		else
			*result = '0';
		result++;
		tab[0]--;
	}
	*result = '\0';
	return (result - tab[1] + 1);
}

static char		*ft_basechar2_10(char *nb)
{
	int		i;
	int		j;
	long	result;

	i = 0;
	j = ft_strlen(nb) - 1;
	result = 0;
	while (j >= 0)
	{
		if (nb[i] == '1')
		{
			result += ft_power(2, j);
		}
		if (nb[i] != '0' && nb[i] != '1')
			return (NULL);
		j--;
		i++;
	}
	return (ft_itoa(result));
}

static char		ft_hex(int c)
{
	if (c >= 0 && c <= 9)
		return (c + 48);
	if (c >= 10 && c <= 15)
		return (c + 55);
	return ('X');
}

static char		*ft_basechar2_16(char *nb)
{
	int		i;
	int		j;
	char	*result;

	j = ft_strlen(nb) % 4;
	if (j == 0)
		i = ft_strlen(nb) / 4;
	else
		i = ft_strlen(nb) / 4 + 1;
	if ((result = (char *)malloc(i * sizeof(char))) == NULL)
		return (NULL);
	if (j > 0)
		*result = ft_hex(ft_atoi(ft_basechar2_10(ft_strsub(nb, 0, j))));
	while ((size_t)j <= ft_strlen(nb))
	{
		result++;
		*result = ft_hex(ft_atoi(ft_basechar2_10(ft_strsub(nb, j, 4))));
		j += 4;
	}
	*result = '\0';
	return (result - i);
}

char			*ft_baseconvch(char *nb, unsigned int from, unsigned int to)
{
	if (from == BINAIRE && to == DECIMAL)
		return (ft_basechar2_10(nb));
	if (from == BINAIRE && to == HEXA)
		return (ft_basechar2_16(nb));
	if (from == DECIMAL && to == BINAIRE)
		return (ft_basechar10_2(nb));
	if (from == DECIMAL && to == HEXA)
		return (ft_basechar2_16(ft_basechar10_2(nb)));
	return (0);
}
