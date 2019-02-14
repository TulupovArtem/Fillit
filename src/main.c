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

static	int ft_count_map(int id)
{
	int x;
	int sharp;

	x = 4;
	sharp = 4;
	while (x * x < id * sharp)
		x++;
	return (x);
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
	if ((ft_create_map(&karta, (karta.weight = ft_count_map(one_tetrimino->id)))) == -1)
		return (-1);
	// ft_first_coordinate(one_tetrimino);
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
		line++;
		characters++;
	}
	if (characters != 4 && (*line != '\0'))
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
        if (((str_nbr % 5) == 0) && *a == NULL)
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
	size_t      str_nbr;
	int			sharp;
	char		**a;

    str_nbr = 0;
	sharp = 0;
    while ((get_next_line(fd, &line)) > 0)
	{
		if (str_nbr == 0)
		{
			if ((one_tetrimino = new_struct(one_tetrimino)) == NULL)
				return (ft_error(one_tetrimino));
			a = one_tetrimino->line;
		}
		str_nbr++;
		*a = line;
		if((sharp = check_line(*a, sharp)) == -1 || (**a == '\0' && (str_nbr % 5) != 0))
			return (ft_error(one_tetrimino));	
		if ((str_nbr % 5) == 0)
		{
			if(((one_tetrimino->next = ft_str_nbr_five(a, one_tetrimino))) == NULL)
				return(ft_error(one_tetrimino));
			one_tetrimino = one_tetrimino->next;
			a = one_tetrimino->line;
			sharp = 0;
		}
		if ((str_nbr % 5) != 0)
			a++;
	}
	if (ft_end_valid(str_nbr, a, one_tetrimino) == -1)
		return (ft_error(one_tetrimino));
	return (0);
}

int		main(int ac, char **av)
{
	int         fd;
	char        *line;

	line  = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1 || ac != 2 || (ft_valid(fd, line) == -1))
	{
		ft_putendl("error");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}