# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 20:14:49 by idunaver          #+#    #+#              #
#    Updated: 2019/02/21 19:28:20 by yperra-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/main.c src/coord.c src/figure.c src/list.c src/map_one.c \
src/map_two.c src/valid_one.c src/valid_two.c src/decision.c

INCLUDE = -I includes/ -I libft/includes

FLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc $(FLAG) $(SRC) $(LIBFT) $(INCLUDE) -o $(NAME)

$(LIBFT):
	@make -C libft/

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all