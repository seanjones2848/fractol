# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 17:18:42 by sjones            #+#    #+#              #
#    Updated: 2017/12/01 13:53:09 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
LFT = -L libft -lft
SRC_PATH =	src
SRC_NAME =	main.c \
			init.c \
			fract.c \
			color.c \
			hooks.c	\
			hooks_plus.c \
			move.c \
			zoom.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ =	$(SRC_NAME:%.c=%.o)
INCL = src/fractol.h
all: $(NAME)

$(NAME):
	@echo "\033[1;33mFractol: Sources compiling... \033[0m"
	@make -C libft/
	@$(CC) $(FLAGS) -I $(INCL) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LFT) $(MLX)
	@echo "\033[1;34mFractol: Compiled with success..!\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;36mFractol binary removed...\033[0m"

re: fclean all
