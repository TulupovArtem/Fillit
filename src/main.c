/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:25:04 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/13 17:01:16 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_error(t_tetris *one_tetrimino)
{	
	freelst(one_tetrimino);
	return (-1);
}

int		main(int ac, char **av)
{
	int         fd;
	char        *line;

	line  = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1 || ac != 2 || ft_valid(fd, line) == -1)
	{
		ft_putendl("error");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}