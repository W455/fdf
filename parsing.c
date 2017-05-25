/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:32:31 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/25 01:56:43 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**      PRINT ERRNO 
*/

int                 ft_puterror(char *s)
{
    ft_putendl_fd(s, 2);
    return (EXIT_FAILURE);
}

/*
**       OPEN THE FD CORRECTLY
*/

int                 ft_open(const char *file_name)
{
    int             fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        exit(ft_puterror(OPEN_ERROR));
    return (fd);
}

/*
**      COUNT THE NB OF COL OF THE FILE
*/

unsigned int        ft_count_words_sep(char *s, int c)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] != ' ' && s[i] != ',' && !ft_isdigit(s[i]) && s[i] != '-')
            exit(ft_puterror(CHAR_ERROR));
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
            j++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (j);
}

/*
**      GET THE NB OF COL AND LINES OF THE FILE AND CHECK INPUTS ERRORS TOO
*/

void                get_and_check(int fd, t_file *file)
{
    int             ret;
    char            *line;
    unsigned int    count;

    count = 1;
    line = NULL;
    if ((ret = get_next_line(fd, &line)) <= 0)
        exit(ft_puterror(READ_ERROR));
    file->col = ft_count_words_sep(line, ' ');
    while ((ret = get_next_line(fd, &line)) >= 0 && count++ > 0)
    {
        if (!ret)
            break;
        if (file->col != ft_count_words_sep(line, ' '))
            exit(ft_puterror(LINE_ERROR));
    }
    if (ret == FAILURE)
        exit(ft_puterror(READ_ERROR));
    file->line = count - 1;
}

/*
**      STORE ALL THE X, Y, Z 
*/

t_point             *get_points(int fd, t_file file)
{
    int             ret;
    int             count;
    char            *line;
    t_point         *point;

    count = 0;
    line = NULL;
    if (!(point = (t_point *)ft_memalloc(sizeof(t_point) *
                                         (file.line * file.col))))
        exit(ft_puterror(MALLOC_ERROR));
    while ((ret = get_next_line((const int)fd, &line)) >= 0)
    {
        while (*line)
        {
            point[count].x = count % file.col;
            point[count].y = count / file.col;
            point[count].color = 0;
            point[count++].z = ft_atoi(line);
            while (*line && *line != ' ')
                line++;
            line = *line ? line + 1 : line;
        }
        if (!ret)
            break;
    }
    {
        int i = 0; //
        while (i < count)
        {
            printf("%d/ x : %d, y = %d, z = %d\n", i, point[i].x, point[i].y, point[i].z);
            i++;
        }
    }
    return (point);
}

/*
**      MANAGE THE CHECK/PARSE PART
*/

t_point             *ft_parsing(char *av, t_file *file)
{
    int             fd;
    t_point         *point;

    fd = ft_open(av);
    get_and_check(fd, file);
    close(fd);
    fd = ft_open(av);
    point = get_points(fd, *file);
    close(fd);
    return (point);
}
/*
int main(int ac, char **av)
{
    t_file file;
    if (ac == 2)
    {
        ft_parsing(av[1], &file);
    }
}
*/
