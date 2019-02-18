/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:47:57 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 18:07:41 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_coord_i(t_coord *coord, t_tetris *one_tetrimino)
{
	int x;
	int y;
	int flag;

	flag = 0;
	x = 0;
	while (one_tetrimino->line[x])
	{
		y = 0;
		while (one_tetrimino->line[x][y])
		{
			if (one_tetrimino->line[x][y] == '#' && flag == 0)
			{
				coord->i_start = x;
				flag = 1;
			}
			if (one_tetrimino->line[x][y] == '#')
				coord->i_end = x;
			y++;
		}
		x++;
	}
}

void	ft_coord_j(t_coord *coord, t_tetris *one_tetrimino)
{
	int x;
	int y;
	int flag;

	flag = 0;
	y = 0;
	x = 0;
	while (one_tetrimino->line[x][y])
	{
		while (one_tetrimino->line[x])
		{
			if (one_tetrimino->line[x][y] == '#' && flag == 0)
			{
				coord->j_start = y;
				flag = 1;
			}
			if (one_tetrimino->line[x][y] == '#')
				coord->j_end = y;
			x++;
		}
		x = 0;
		y++;
	}
}
