/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:32:05 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 13:46:25 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int ft_count_map_extra(t_tetris *one_tetrimino)
{
	t_coord 		coord;
	t_count_extra	count;

	count.height2 = 0;
	count.width2 = 0;
	while (one_tetrimino)
	{
		if (!one_tetrimino->next)
		{
			ft_coord_i(&coord, one_tetrimino);
			count.height1 = coord.i_end - coord.i_start + 1;
			ft_coord_j(&coord, one_tetrimino);
			count.width1 = coord.j_end - coord.j_start + 1;
		}
		if (one_tetrimino->next)
		{
			ft_coord_i(&coord, one_tetrimino);
			count.height2 = coord.i_end - coord.i_start + 1;
			ft_coord_j(&coord, one_tetrimino);
			count.width2 = coord.j_end - coord.j_start + 1;
		}
		one_tetrimino = one_tetrimino->previous;
	}
	return (ft_help_count(&count));
}

int ft_count_map(t_tetris *one_tetrimino)
{
	int x;
	int sharp;

	sharp = 4;
	if (one_tetrimino->id > 2)
	{
		x = 4;
		while (x * x < one_tetrimino->id * sharp)
			x++;
	}
	else
		x  = ft_count_map_extra(one_tetrimino);
	return (x);
}

void ft_print_map(t_map *karta)
{
	char **temp;

	temp = karta->map;
	while (*temp)
	{
		write(1, *temp, karta->weight);
		ft_putchar('\n');
		temp++;
	}
}

void	ft_free_map(char **map)
{
	char	**point_map;

	point_map = map;
	while (*point_map)
		ft_strdel(point_map++);
	free (map);
}

int	ft_create_map(t_map *karta, int x)
{
	char	**line;
	int		str;

	str = x;
	if (karta->map)
		ft_free_map(karta->map);
	if (!(karta->map = (char **)malloc((x + 1) * sizeof(char*))))
		return (-1);
	karta->map[x] = NULL;
	line = karta->map;
	while (str--)
	{
		if (!(*line = (char *)malloc((x + 1) * sizeof(char))))
		{
			ft_free_map(karta->map);
			return (-1);
		}
		ft_bzero(*line, x + 1);
		ft_memset(*line, '.', x);
		line++;
	}
	ft_print_map(karta);
	return (1);
}