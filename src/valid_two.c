/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:30:23 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 16:28:17 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_up_down(t_sharp *sharp)
{
	if (sharp->x != 0) //проверка сверху
	{
		sharp->x--;
		if (sharp->p_line[sharp->x][sharp->y] == '#')
			sharp->i++;
		sharp->x++;
	}
	if (sharp->x != 3) //проверка снизу
	{
		sharp->x++;
		if (sharp->p_line[sharp->x][sharp->y] == '#')
			sharp->i++;
		sharp->x--;
	}
}

void	ft_left_right(t_sharp *sharp)
{
	if (sharp->y != 4) //проверка справа
	{
		sharp->y++;
		if (sharp->p_line[sharp->x][sharp->y] == '#')
			sharp->i++;
		sharp->y--;
	}
	if (sharp->y != 0) //проверка слева
	{
		sharp->y--;
		if (sharp->p_line[sharp->x][sharp->y] == '#')
			sharp->i++;
		sharp->y++;
	}
}

int		ft_check_connect(t_sharp *sharp)
{
	while (sharp->p_line[sharp->x])
	{
		while (sharp->p_line[sharp->x][sharp->y])
		{
			if (sharp->p_line[sharp->x][sharp->y] == '#')
			{
				ft_left_right(sharp);
				ft_up_down(sharp);
			}
			sharp->y++;
		}
		sharp->y = 0;
		sharp->x++;
	}
	sharp->x = 0;
	return(sharp->i);
}

int		lst_sharp_connecting(t_tetris *one_tetrimino)
{
	t_tetris	*temp;
	t_sharp		sharp;

	sharp.x = 0;
	sharp.y = 0;
	sharp.i = 0;
	temp = one_tetrimino;
	sharp.p_line = temp->line;
	while (temp)
	{
		sharp.i = ft_check_connect(&sharp);
		if (sharp.i != 6 && sharp.i != 8)
			return (-1);
		else
		{
			sharp.i = 0;
			temp = temp->previous;
			if (temp)
				sharp.p_line = temp->line;
		}
	}
	return (0);
}