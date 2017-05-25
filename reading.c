/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkirsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:06:07 by pkirsch           #+#    #+#             */
/*   Updated: 2017/04/20 13:07:10 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define MAX_INPUT 25 * 21 + 20
#define SUCCESS 1
#define FAILURE 0

int				ft_open(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	return (fd);
}

char			*ft_read(int fd)
{
	int		sum;
	int		ret;
	char	buff[MAX_INPUT + 1];
	char	dst[MAX_INPUT + 1];
	char	*s;

	dst[0] = '\0';
	sum = 0;
	while (sum <= MAX_INPUT && (ret = read(fd, buff, MAX_INPUT)) > 0)
	{
		sum += ret;
		buff[ret] = '\0';
		ft_strcat(dst, buff);
	}
	if (ret < 0)
		return (NULL);
	else if (sum > MAX_INPUT)
		return (NULL);
	s = dst;
	return (s);
}
