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

void ft_print_figure(char **figure, int id)
{
	ft_putnbr(id);
	ft_putchar('\n');
	while (*figure)
	{
		ft_putendl(*figure);
		figure++;
	}
	id++;
}

static	void	ft_free_map(char **map)
{
	char	**point_map;

	point_map = map;
	while (*point_map)
		ft_strdel(point_map++);
	free (map);
}

static	int	ft_create_map(t_map *karta, int x)
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

static	void	ft_coord_i(t_coord *coord, t_tetris *one_tetrimino)
{
	int x;
	int y;
	int flag;

	flag = 0;
	x = 0;
	while (one_tetrimino->line[x])
	{
		y = 0;
		while (one_tetrimino->line[x][y])
		{
			if (one_tetrimino->line[x][y] == '#' && flag == 0)
			{
				coord->i_start = x;
				flag = 1;
			}
			if (one_tetrimino->line[x][y] == '#')
				coord->i_end = x;
			y++;
		}
		x++;
	}
}

static	void	ft_coord_j(t_coord *coord, t_tetris *one_tetrimino)
{
	int x;
	int y;
	int flag;

	flag = 0;
	y = 0;
	x = 0;
	while (one_tetrimino->line[x][y])
	{
		while (one_tetrimino->line[x])
		{
			if (one_tetrimino->line[x][y] == '#' && flag == 0)
			{
				coord->j_start = y;
				flag = 1;
			}
			if (one_tetrimino->line[x][y] == '#')
				coord->j_end = y;
			x++;
		}
		x = 0;
		y++;
	}
}

static int ft_help_count(t_count_extra *count)
{
	int x;
	int y;

	if (count->height1 >= count->width1)
		x = count->height1;
	else
		x = count->width1;
	if (count->height1 >= count->width1)
		y = count->height2;
	else
		y = count->width2;
	if (x >= y)
		return(x);
	return (y);
}

static int ft_count_map_extra(t_tetris *one_tetrimino)
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

static	int ft_count_map(t_tetris *one_tetrimino)
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

static	int	ft_create_figure(t_coord *coord, t_tetris *one_tetrimino)
{
	char **figure_temp;
	int x;

	one_tetrimino->width = coord->j_end - coord->j_start + 1;
	one_tetrimino->height = coord->i_end - coord->i_start + 1;
	x = 0;
	if (!(figure_temp = (char **)malloc((one_tetrimino->height + 1) * sizeof(char *))))
		return (-1);
	while (coord->i_start <= coord->i_end)
	{
		figure_temp[x] = ft_strsub(one_tetrimino->line[coord->i_start], coord->j_start, one_tetrimino->width);
		coord->i_start++;
		x++;
	}
	figure_temp[x] = NULL;
	ft_free_map(one_tetrimino->line);
	one_tetrimino->line = figure_temp;
	return (0);
}

static	int	ft_made_figure(t_tetris *one_tetrimino)
{
	t_coord	coord;
	int		id;

	id = 1;
	while (one_tetrimino)
	{
		ft_coord_i(&coord, one_tetrimino);
		ft_coord_j(&coord, one_tetrimino);
		ft_create_figure(&coord, one_tetrimino);
		ft_print_figure(one_tetrimino->line, id++);
		one_tetrimino = one_tetrimino->previous;
	}
	return (0);
}

static void		ft_line_null(char **current_line)
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

static	t_tetris	*new_struct(t_tetris *one_tetrimino)
{
	if (!(one_tetrimino = (t_tetris*)malloc(sizeof(t_tetris))))  // выделяем память под структуру
		return (NULL);
	one_tetrimino->next = NULL;
	one_tetrimino->previous = NULL;
	if (!(one_tetrimino->line = (char**)malloc(5 * sizeof(char*)))) // выделяем память под элемент структуры для карты одной тетрамино
		return (NULL);
	ft_line_null(one_tetrimino->line);
	one_tetrimino->id = 1;
	return(one_tetrimino);
}

static	t_tetris	*add_struct(t_tetris *one_tetrimino)
{
	t_tetris		*current;

	current = one_tetrimino;
	if (!(current->next = (t_tetris*)malloc(sizeof(t_tetris)))) // выделяем память под следующую структуру
		return (NULL);
	current = current->next;
	current->previous = one_tetrimino;
	current->next = NULL;
	if (!(current->line = (char**)malloc(5 * sizeof(char*)))) // выделяем память под следующий элемент структуры для карты одной тетрамино
		return (NULL);
	ft_line_null(current->line);
	current->id = 1 + one_tetrimino->id;
	if (one_tetrimino->id > 26) //  проверка на 26 фигурок
		return (NULL);
	return (current);
}

static	void	freelst(t_tetris *one_tetrimino) // очистка всех элементов структуры
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

int	ft_error(t_tetris *one_tetrimino)
{	
	freelst(one_tetrimino);
	return (-1);
}

static	int		lst_sharp_connecting(t_tetris *one_tetrimino)
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

static	int	check_line(char *line, int sharp) // проверка линий на валидные символы и подсчет решеток
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

static t_tetris *ft_str_nbr_five(char **a, t_tetris *one_tetrimino) // проверка кратных линий
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

static t_tetris *ft_valid_extra(t_tetris *one_tetrimino, t_valid *valid, char *line)
{
    if (valid->str_nbr == 0)
	{
		if ((one_tetrimino = new_struct(one_tetrimino)) == NULL)
			return (NULL);
		valid->a = one_tetrimino->line;
	}
	*valid->a = line;
	valid->str_nbr++;
	if((valid->sharp = check_line(*valid->a, valid->sharp)) == -1 || (**valid->a != '\0' && valid->str_nbr % 5 == 0))
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