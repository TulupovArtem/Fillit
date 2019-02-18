/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:30:23 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 13:30:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		lst_sharp_connecting(t_tetris *one_tetrimino)
{
	t_tetris	*temp;
	char		**array;
	int			x;
	int 		y;
	int			i;
	t_map		karta;

	x = 0;
	i = 0;
	y = 0;
	temp = one_tetrimino;
	array = temp->line;
	while (temp)
	{
		while (array[x])
		{
			while (array[x][y])
			{
				if (array[x][y] == '#')
				{
					if (y != 4) //проверка справа
					{
						y++;
						if (array[x][y] == '#')
							i++;
						y--;
					}
					
					if (y != 0) //проверка слева
					{
						y--;
						if (array[x][y] == '#')
							i++;
						y++;
					}
					if (x != 0) //проверка сверху
					{
						x--;
						if (array[x][y] == '#')
							i++;
						x++;
					}
					if (x != 3) //проверка снизу
					{
						x++;
						if (array[x][y] == '#')
							i++;
						x--;
					}
				}
				y++;
			}
			y = 0;
			x++;
		}
		x = 0;
		if (i != 6 && i != 8)
			return (-1);
		else
		{
			i = 0;
			temp = temp->previous;
			if (temp)
				array = temp->line;
		}
	}
	karta.map = NULL;
	if (ft_create_map(&karta, (karta.weight = ft_count_map(one_tetrimino))) == -1)
		return (-1);
	ft_made_figure(one_tetrimino);
	return (0);
}