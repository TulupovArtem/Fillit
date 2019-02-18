/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:35:39 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 16:21:13 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// void ft_print_figure(char **figure)
// {
// 	while (*figure)
// 	{
// 		ft_putendl(*figure);
// 		figure++;
// 	}
// 	ft_putchar('\n');
// }

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
		if(!(figure_temp[x] = ft_strsub(one_tetrimino->line[coord->i_start],
		coord->j_start, one_tetrimino->width)))
		{
			ft_free_map(figure_temp);
			return (-1);
		}
		coord->i_start++;
		x++;
	}
	figure_temp[x] = NULL;
	ft_free_map(one_tetrimino->line);
	one_tetrimino->line = figure_temp;
	return (0);
}

t_tetris	*ft_made_figure(t_tetris *one_tetrimino)
{
	t_coord		coord;
	t_tetris	*temp;

	temp = one_tetrimino;
	while (temp)
	{
		ft_coord_i(&coord, temp);
		ft_coord_j(&coord, temp);
		if (ft_create_figure(&coord, temp) == -1)
		{
			freelst(one_tetrimino);
			return (NULL);
		}
		// ft_print_figure(temp->line);
		temp = temp->previous;
	}
	return (temp);
}