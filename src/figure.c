/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:35:39 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 13:40:34 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void ft_print_figure(char **figure, int id)
{
	ft_putnbr(id);
	ft_putchar('\n');
	while (*figure)
	{
		ft_putendl(*figure);
		figure++;
	}
	id++;
}

int	ft_create_figure(t_coord *coord, t_tetris *one_tetrimino)
{
	char **figure_temp;
	int x;

	one_tetrimino->width = coord->j_end - coord->j_start + 1;
	one_tetrimino->height = coord->i_end - coord->i_start + 1;
	x = 0;
	if (!(figure_temp = (char **)malloc((one_tetrimino->height + 1) * sizeof(char *))))
		return (-1);
	while (coord->i_start <= coord->i_end)
	{
		figure_temp[x] = ft_strsub(one_tetrimino->line[coord->i_start], coord->j_start, one_tetrimino->width);
		coord->i_start++;
		x++;
	}
	figure_temp[x] = NULL;
	ft_free_map(one_tetrimino->line);
	one_tetrimino->line = figure_temp;
	return (0);
}

int	ft_made_figure(t_tetris *one_tetrimino)
{
	t_coord	coord;
	int		id;

	id = 1;
	while (one_tetrimino)
	{
		ft_coord_i(&coord, one_tetrimino);
		ft_coord_j(&coord, one_tetrimino);
		ft_create_figure(&coord, one_tetrimino);
		ft_print_figure(one_tetrimino->line, id++);
		one_tetrimino = one_tetrimino->previous;
	}
	return (0);
}