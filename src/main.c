/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:31:03 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/18 18:31:16 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_error_close(int fd)
{
	ft_putendl("error");
	close(fd);
	return (-1);
}

t_tetris	*ft_error(t_tetris *one_tetrimino)
{
	freelst(one_tetrimino);
	return (NULL);
}

int			main(int ac, char **av)
{
	int			fd;
	char		*line;
	t_tetris	*one_tetrimino;

	one_tetrimino = NULL;
	line = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1 || ac != 2 ||
	(one_tetrimino = ft_valid(fd, line, one_tetrimino)) == NULL)
		return (ft_error_close(fd));
	if ((ft_decision(one_tetrimino)) == -1)
		return (ft_error_close(fd));
	close(fd);
	return (0);
}
