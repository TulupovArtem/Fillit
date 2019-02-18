/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:57:44 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/18 19:36:16 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_set(char **figure, int x, int y, t_map *karta)
{

}

int	ft_check(char **figure, int x, int y, t_map *karta)
{
	int i;
	int j;

	i = 0;
	while (figure[i])
	{
		j = 0;
		while (figure[i][j])
		{
			if (figure[i][j] == '#' && karta->map[i + x][j + y])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_try(char **figure, int x, int y, t_map *karta)
{
	if (ft_check(figure, x, y, karta) == 0)
		ft_set(figure, x, y, karta);
	else
	{
		if (len)
		{

		}
		ft_try(figure, x, y++, karta);
	return;
}

int		ft_decision(t_tetris *one_tetrimino)
{
	t_map	karta;
	int		x;
	int		y;

	x = 0;
	y = 0;
	karta.map = NULL;
	if (ft_create_map(&karta, (karta.weight =
	ft_count_map(one_tetrimino))) == -1)
		return (-1);
	one_tetrimino = ft_made_figure(one_tetrimino);
	ft_try(one_tetrimino->line, x, y, &karta);
	return (0);
}
