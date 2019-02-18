/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:57:44 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/18 18:08:41 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_decision(t_tetris *one_tetrimino)
{
	t_map	karta;

	karta.map = NULL;
	if (ft_create_map(&karta, (karta.weight =
	ft_count_map(one_tetrimino))) == -1)
		return (-1);
	one_tetrimino = ft_made_figure(one_tetrimino);
	return (0);
}
