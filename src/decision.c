/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:57:44 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/19 19:03:19 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_set(t_tetris *one_tetrimino, int x, int y, t_map *karta)
{
	int i;
	int j;

	i = 0;
	while (one_tetrimino->line[i])
	{
		j = 0;
		while (one_tetrimino->line[i][j])
		{
			if (one_tetrimino->line[i][j] != '.')
				karta->map[x + i][y + j] = 'A' + one_tetrimino->id - 1;
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check(char **figure, int x, int y, t_map *karta)
{
	int i;
	int j;

	i = 0;
	while (figure[i])
	{
		j = 0;
		while (figure[i][j])
		{
			if (figure[i][j] != '.' && karta->map[i + x][j + y] != '.')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_reset(char **figure, int x, int y, t_map *karta)
{
	int i;
	int j;

	i = 0;
	while (figure[i])
	{
		j = 0;
		while (figure[i][j])
		{
			if (figure[i][j] != '.')
				karta->map[i + x][j + y] = '.';
			j++;
		}
		i++;
	}
}

int		ft_try(t_tetris *one_tetrimino, int x, int y, t_map *karta)
{
	int res;

	res = 0;
	if (ft_check(one_tetrimino->line, x, y, karta) == 0)
	{
		ft_set(one_tetrimino, x, y, karta);
		if (one_tetrimino->next)
		{
			if ((res = ft_try(one_tetrimino->next, 0, 0, karta)) == 0)
				ft_reset(one_tetrimino->line, x, y, karta);
		}
		else
			return (1);
	}
	if (res == 1)
		return (1);
	if (y + 1 + one_tetrimino->width <= karta->weight)
		res = ft_try(one_tetrimino, x, y + 1, karta);
	else if (x + 1 + one_tetrimino->height <= karta->weight)
		res = ft_try(one_tetrimino, x + 1, 0, karta);
	return (res);
}

int		ft_decision(t_tetris *one_tetrimino)
{
	t_map	karta;

	karta.map = NULL;
	if (ft_create_map(&karta, (karta.weight =
	ft_count_map(one_tetrimino))) == -1)
		return (-1);
	one_tetrimino = ft_made_figure(one_tetrimino);
	while (ft_try(one_tetrimino, 0, 0, &karta) == 0)
		ft_create_map(&karta, ++karta.weight);
	ft_print_map(&karta);
	return (0);
}
