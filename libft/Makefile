# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 16:13:52 by idunaver          #+#    #+#              #
#    Updated: 2019/02/21 18:59:02 by yperra-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memccpy.c \
src/ft_memmove.c src/ft_memchr.c src/ft_memcmp.c src/ft_strlen.c \
src/ft_strdup.c src/ft_strcpy.c src/ft_strncpy.c src/ft_strcat.c \
src/ft_strncat.c src/ft_strlcat.c src/ft_strchr.c src/ft_strrchr.c \
src/ft_strstr.c src/ft_strnstr.c src/ft_strcmp.c src/ft_strncmp.c \
src/ft_atoi.c src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c \
src/ft_toupper.c src/ft_tolower.c src/ft_memalloc.c src/ft_memdel.c \
src/ft_strnew.c src/ft_strdel.c src/ft_strclr.c src/ft_striter.c \
src/ft_striteri.c src/ft_strmap.c src/ft_strmapi.c src/ft_strequ.c \
src/ft_strnequ.c src/ft_strsub.c src/ft_strjoin.c src/ft_strtrim.c \
src/ft_strsplit.c src/ft_itoa.c src/ft_putchar.c src/ft_putstr.c \
src/ft_putendl.c src/ft_putnbr.c src/ft_putchar_fd.c src/ft_putstr_fd.c \
src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_range.c src/ft_sqrt.c \
src/ft_swap.c src/ft_isprint.c src/ft_isascii.c src/ft_lstnew.c \
src/ft_lstdelone.c src/ft_lstdel.c src/ft_lstadd.c src/ft_lstiter.c \
src/ft_lstmap.c src/ft_isupper.c src/ft_islower.c src/ft_lstend.c \
src/get_next_line.c

INCLUDE = -I includes/

OBJ = src/ft_memset.o src/ft_bzero.o src/ft_memcpy.o src/ft_memccpy.o \
src/ft_memmove.o src/ft_memchr.o src/ft_memcmp.o src/ft_strlen.o \
src/ft_strdup.o src/ft_strcpy.o src/ft_strncpy.o src/ft_strcat.o \
src/ft_strncat.o src/ft_strlcat.o src/ft_strchr.o src/ft_strrchr.o \
src/ft_strstr.o src/ft_strnstr.o src/ft_strcmp.o src/ft_strncmp.o \
src/ft_atoi.o src/ft_isalpha.o src/ft_isdigit.o src/ft_isalnum.o \
src/ft_toupper.o src/ft_tolower.o src/ft_memalloc.o src/ft_memdel.o \
src/ft_strnew.o src/ft_strdel.o src/ft_strclr.o src/ft_striter.o \
src/ft_striteri.o src/ft_strmap.o src/ft_strmapi.o src/ft_strequ.o \
src/ft_strnequ.o src/ft_strsub.o src/ft_strjoin.o src/ft_strtrim.o \
src/ft_strsplit.o src/ft_itoa.o src/ft_putchar.o src/ft_putstr.o \
src/ft_putendl.o src/ft_putnbr.o src/ft_putchar_fd.o src/ft_putstr_fd.o \
src/ft_putendl_fd.o src/ft_putnbr_fd.o src/ft_range.o src/ft_sqrt.o \
src/ft_swap.o src/ft_isprint.o src/ft_isascii.o src/ft_lstnew.o \
src/ft_lstdelone.o src/ft_lstdel.o src/ft_lstadd.o src/ft_lstiter.o \
src/ft_lstmap.o src/ft_isupper.o src/ft_islower.o src/ft_lstend.o \
src/get_next_line.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

src/%.o: src/%.c
	@gcc $(FLAG) $(INCLUDE) -c $< -o $@ 

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all