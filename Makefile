# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 18:14:05 by hel-hadi          #+#    #+#              #
#    Updated: 2016/12/28 18:23:41 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl
PREF = ./srcs/
HEADER = ./include/

OBJ = $(SRC:.c=.o)
OBJ1 = objets/*.o
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
		clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
		@echo "\033[34m === Creation de l executable ===\033[0m"


clean	:
	rm -rf *.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement Librairie ====\033[0m"

.PHONY: clean fclean re
