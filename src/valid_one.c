/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:20:28 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/18 14:01:46 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	check_line(char *line, int sharp) // проверка линий на валидные символы и подсчет решеток
{
    int     characters;

    characters = 0;
    while (*line)
	{
		if (*line != '.' && *line != '#')
			return (-1);
		if (*line == '#')
			sharp++;
		line++;
		characters++;
	}
	if (characters != 4)
		return (-1);
    return(sharp);
}

t_tetris *ft_str_nbr_five(char **a, t_tetris *one_tetrimino) // проверка кратных линий
{
    if (**a == '\0')
	{
		free(*a);
		*a = NULL;
		if (!(one_tetrimino->next = add_struct(one_tetrimino)))
			return (NULL);
		one_tetrimino = one_tetrimino->next;
		one_tetrimino->next = NULL;
	}
	else if (**a != '\0')
		return (NULL);
	return (one_tetrimino);
}

t_tetris *ft_valid_extra(t_tetris *one_tetrimino, t_valid *valid, char *line)
{
    if (valid->str_nbr == 0)
	{
		if ((one_tetrimino = new_struct(one_tetrimino)) == NULL)
			return (NULL);
		valid->a = one_tetrimino->line;
	}
	*valid->a = line;
	valid->str_nbr++;
	if(((valid->sharp = check_line(*valid->a, valid->sharp)) == -1
	&& valid->str_nbr % 5 != 0) || (**valid->a != '\0' && valid->str_nbr % 5 == 0))
		return (NULL);
	if (valid->str_nbr % 5 == 0)
	{
		if(((one_tetrimino->next = ft_str_nbr_five(valid->a, one_tetrimino))) == NULL)
			return(NULL);
		one_tetrimino = one_tetrimino->next;
		valid->a = one_tetrimino->line;
		valid->sharp = 0;
	}
	if (valid->str_nbr % 5 != 0)
		valid->a++;
    return (one_tetrimino);
}

int ft_end_valid(int str_nbr, char **a, t_tetris *one_tetrimino)
{
    if (str_nbr > 0)
    {
        if ((str_nbr % 5 == 0) && *a == NULL)
            return (-1);
        else
        {
            a++;
            a = NULL;
        }
        if (lst_sharp_connecting(one_tetrimino) == -1)
            return(-1);
    }
    else
        return (-1);
	return (0);
}

int ft_valid(int fd, char *line)
{
    t_tetris    *one_tetrimino = NULL;
	t_valid		valid;

	valid.a = NULL;
    valid.str_nbr = 0;
	valid.sharp = 0;
    while ((get_next_line(fd, &line)) > 0)
	{
		if(!(one_tetrimino = ft_valid_extra(one_tetrimino, &valid, line)))
			return (ft_error(one_tetrimino));
	}
	if (ft_end_valid(valid.str_nbr, valid.a, one_tetrimino) == -1)
		return (ft_error(one_tetrimino));
	return (0);
}