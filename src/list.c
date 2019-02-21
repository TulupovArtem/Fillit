/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:25:37 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/21 15:31:12 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_line_null(char **current_line)
{
	char		**line;
	int			count_line;

	count_line = 5;
	line = current_line;
	while (count_line--)
	{
		*line = NULL;
		line++;
	}
}

t_tetris	*new_struct(t_tetris *one_tetrimino)
{
	if (!(one_tetrimino = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	one_tetrimino->next = NULL;
	one_tetrimino->previous = NULL;
	if (!(one_tetrimino->line = (char**)malloc(5 * sizeof(char*))))
		return (NULL);
	ft_line_null(one_tetrimino->line);
	one_tetrimino->id = 1;
	return (one_tetrimino);
}

t_tetris	*add_struct(t_tetris *one_tetrimino)
{
	t_tetris		*current;

	current = one_tetrimino;
	if (!(current->next = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	current = current->next;
	current->previous = one_tetrimino;
	current->next = NULL;
	if (!(current->line = (char**)malloc(5 * sizeof(char*))))
		return (NULL);
	ft_line_null(current->line);
	current->id = 1 + one_tetrimino->id;
	if (one_tetrimino->id > 26)
		return (NULL);
	return (current);
}

void		freelst(t_tetris *one_tetrimino)
{
	char		**line_temp;
	t_tetris	*current;

	current = one_tetrimino;
	if (current == NULL)
		return ;
	else
	{
		while (current != NULL)
		{
			line_temp = current->line;
			one_tetrimino = current;
			while (*line_temp)
			{
				free(*line_temp);
				*line_temp = NULL;
				line_temp++;
			}
			free(one_tetrimino->line);
			current = one_tetrimino->previous;
			free(one_tetrimino);
		}
	}
}

void		freelst_next(t_tetris *one_tetrimino)
{
	char		**line_temp;
	t_tetris	*current;

	current = one_tetrimino;
	if (current == NULL)
		return ;
	else
	{
		while (current != NULL)
		{
			line_temp = current->line;
			one_tetrimino = current;
			while (*line_temp)
			{
				free(*line_temp);
				*line_temp = NULL;
				line_temp++;
			}
			free(one_tetrimino->line);
			current = one_tetrimino->next;
			free(one_tetrimino);
		}
	}
}
