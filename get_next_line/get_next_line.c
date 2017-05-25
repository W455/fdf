/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:14:58 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/24 01:57:00 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoinandfree(char *s1, char *s2)
{
	char			*str;

	if (!s1 || !*s1)
	{
		str = ft_strdup(s2);
		ft_strdel(&s2);
		return (str);
	}
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_strncat(str, s2, ft_strlen(s2));
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}

static t_gnl		ft_read(int const fd, t_gnl gnl)
{
	if (gnl.i == gnl.size)
	{
		gnl.i = 0;
		if ((gnl.size = read(fd, gnl.buff, BUFF_SIZE)) == FAILURE)
			gnl.i = FAILURE;
		else
			gnl.buff[gnl.size] = '\0';
	}
	return (gnl);
}

static int			build_line(char **line, t_gnl gnl, char offset)
{
	int				index;
	char			*save;

	index = 0;
	if (!(save = ft_strnew(gnl.size + 1)))
		return (FAILURE);
	while (gnl.i < gnl.size)
	{
		if (gnl.buff[gnl.i] == offset
						&& (*line = ft_strjoinandfree(*line, save)))
			return (gnl.i);
		save[index++] = gnl.buff[gnl.i++];
		if (gnl.i == gnl.size && (*line = ft_strjoinandfree(*line, save)))
			return (gnl.i);
		if (!*line)
			return ((gnl.i = FAILURE));
	}
	return (gnl.i);
}

int					get_next_offset(int const fd, char **line, char offset)
{
	static t_gnl	gno[MAX_FD];

	if (!line || fd < 0 || fd >= MAX_FD)
		return (FAILURE);
	gno[fd] = ft_read(fd, gno[fd]);
	if (gno[fd].i == FAILURE || !(*line = ft_strnew(0)))
		return (FAILURE);
	while (gno[fd].size)
	{
		if (gno[fd].buff[gno[fd].i] == offset)
		{
			++gno[fd].i;
			return (SUCCESS);
		}
		gno[fd].i = build_line(line, gno[fd], offset);
		gno[fd] = ft_read(fd, gno[fd]);
		if (gno[fd].i == FAILURE)
			return (FAILURE);
	}
	if (**line)
		return (SUCCESS);
	return (EOFF);
}

int					get_next_line(int const fd, char **line)
{
	return (get_next_offset(fd, line, '\n'));
}
