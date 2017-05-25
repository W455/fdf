/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:15:56 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/25 01:46:39 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**  USUAL DEFINES
*/

# define FAILURE -1
# define SUCCESS 1
# define OK 1
# define FALSE -1

/*
**  ERROR MSGS
*/

# define MALLOC_ERROR "Error : malloc =0"
# define READ_ERROR "Error : read  =/"
# define OPEN_ERROR "Error : open X|"
# define LINE_ERROR "Error : wrong line lenght 3=]"
# define CHAR_ERROR "Error : wrong char in file =3"



# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "mlx.h"

typedef struct              s_point
{
    int                     x;
    int                     y;
    int                     z;
    int                     color;
    int                     s;
}                           t_point;

typedef struct              s_file
{
    unsigned int            line;
    unsigned int            col;
}                           t_file;

t_point             *ft_parsing(char *av, t_file *file);

#endif
