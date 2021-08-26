# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 21:06:07 by tschmitt          #+#    #+#              #
#    Updated: 2021/08/26 17:46:25 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

INCLUDE = ./include/ 
LIBFT_INCLUDE = ./libs/libft/include/

LIBFT_NAME = ./libs/libft/lib/libft.a

SRC = ./src/main.c ./src/draw_map.c ./src/parse_map.c

MLX_FLAGS = -I ./libs/mlx/ -L ./libs/mlx -lmlx -framework OpenGL -framework AppKit

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./libs/libft/
	@make -C ./libs/mlx/
	$(CC) $(CCFLAGS) -I $(INCLUDE) -I $(LIBFT_INCLUDE) $(MLX_FLAGS) $(SRC) $(LIBFT_NAME) -o $(NAME)

clean:
	@make -C ./libs/libft/ clean
	@make -C ./libs/mlx/ clean

fclean: clean
	@echo $(R)Cleaning" "[$(NAME)]...$(X)
	@make -C ./libs/libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re