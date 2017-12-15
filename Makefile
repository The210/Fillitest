# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 16:33:39 by ybouzgao          #+#    #+#              #
#    Updated: 2017/12/15 17:07:56 by ybouzgao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRCS =  ft_sqrt.c ft_strtrimc.c ft_itoa.c ft_strsplit.c ft_strnew.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcmp.c ft_atoi.c ft_fill_tetri.c ft_checkvalid.c ft_putstr_improved.c resolve_recursive.c ft_calcul_fonctions.c ft_checks.c ft_test_and_draw.c ft_max_size.c ft_freestr.c ft_strcmp_improved.c ft_erase.c ft_findcoord.c
OBJ = ft_sqrt.o ft_strtrimc.o ft_itoa.o ft_strsplit.o ft_strnew.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcmp.o ft_atoi.o ft_fill_tetri.o ft_checkvalid.o ft_putstr_improved.o resolve_recursive.o ft_calcul_fonctions.o ft_checks.o ft_test_and_draw.o ft_max_size.o ft_freestr.o ft_strcmp_improved.o ft_erase.o ft_findcoord.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRCS)
	ar rc $(NAME) $(OBJ)
	gcc $(FLAG) -o fillit main.c $(SRCS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) fillit

re: fclean all
