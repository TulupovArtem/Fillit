/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:09:00 by yperra-f          #+#    #+#             */
/*   Updated: 2019/02/18 18:24:43 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <libc.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct			s_sharp
{
	int					x;
	int					y;
	int					i;
	char				**p_line;
}						t_sharp;

typedef struct			s_count_extra
{
	int					height1;
	int					height2;
	int					width1;
	int					width2;
}						t_count_extra;

typedef struct			s_valid
{
	char				**a;
	int					str_nbr;
	int					sharp;
}						t_valid;

typedef struct			s_coord
{
	int					i_start;
	int					i_end;
	int					j_start;
	int					j_end;
}						t_coord;

typedef struct			s_map
{
	char				**map;
	int					weight;
}						t_map;

typedef struct			s_tetris
{
	int					id;
	char				**line;
	int					height;
	int					width;
	struct s_tetris		*next;
	struct s_tetris		*previous;
}						t_tetris;

t_tetris				*ft_error(t_tetris *one_tetrimino);
int						ft_error_close(int fd);
t_tetris				*ft_valid(int fd, char *line, t_tetris *one_tetrimino);
int						check_line(char *line, int sharp);
t_tetris				*ft_str_nbr_five(char **a, t_tetris *one_tetrimino);
t_tetris				*ft_valid_extra(t_tetris *one_tetrimino,
t_valid *valid, char *line);
int						ft_end_valid(int str_nbr, char **a,
t_tetris *one_tetrimino);
int						lst_sharp_connecting(t_tetris *one_tetrimino);
int						ft_check_connect(t_sharp *sharp);
void					ft_left_right(t_sharp *sharp);
void					ft_up_down(t_sharp *sharp);
void					ft_line_null(char **current_line);
t_tetris				*add_struct(t_tetris *one_tetrimino);
t_tetris				*new_struct(t_tetris *one_tetrimino);
void					freelst(t_tetris *one_tetrimino);
int						ft_create_map(t_map *karta, int x);
void					ft_free_map(char **map);
void					ft_print_map(t_map *karta);
int						ft_count_map(t_tetris *one_tetrimino);
int						ft_count_map_extra(t_tetris *one_tetrimino);
int						ft_help_count(t_count_extra *count);
t_tetris				*ft_made_figure(t_tetris *one_tetrimino);
void					ft_print_figure(char **figure);
int						ft_create_figure(t_coord *coord,
t_tetris *one_tetrimino);
void					ft_coord_i(t_coord *coord, t_tetris *one_tetrimino);
void					ft_coord_j(t_coord *coord, t_tetris *one_tetrimino);
int						ft_decision(t_tetris *one_tetrimino);

#endif
