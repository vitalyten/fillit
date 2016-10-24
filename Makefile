# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/18 13:34:21 by vtenigin          #+#    #+#              #
#    Updated: 2016/10/20 20:54:29 by vtenigin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft.a
NAME = fillit
SRC =	main.c \
		tettest.c \
		readfile.c

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -L libft -l ft

clean:
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all


###.
###.
#...
#...

1
1+1
0+1+1*4