/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:08:47 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/13 17:10:01 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct      s_map
{
    char            **map;
    int             weight;
}                   t_map;

typedef struct      s_tetris
{
    int             id;
    char            **line;
    struct s_tetris *next;
    struct s_tetris *previous;
}                   t_tetris;

int	main(int ac, char **av);

#endif