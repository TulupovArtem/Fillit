/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:09:00 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/18 12:50:07 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <libc.h>
# include "../gnl/get_next_line.h"

typedef struct      s_count_extra
{
    int             height1;
    int             height2;
    int             width1;
    int             width2;
}                   t_count_extra;

typedef struct      s_valid
{
    char            **a;
    int             str_nbr;
    int             sharp;
}                   t_valid;

typedef struct      s_coord
{
    int             i_start;
    int             i_end;
    int             j_start;
    int             j_end;
}                   t_coord;

typedef struct      s_map
{
    char            **map;
    int             weight;
}                   t_map;

typedef struct      s_tetris
{
    int             id;
    char            **line;
    int             height;
    int             width;
    struct s_tetris *next;
    struct s_tetris *previous;
}                   t_tetris;

#endif
