# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 21:06:07 by tschmitt          #+#    #+#              #
#    Updated: 2021/08/28 16:41:18 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang
CCFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/mlx/

SRC_PATH = ./src/
OBJ_PATH = ./obj/

INCLUDE = ./include/ 
LIBFT_INCLUDE = $(LIBFT_PATH)include/
MLX_INCLUDE = $(MLX_PATH)

LIBFT_NAME = $(LIBFT_PATH)lib/libft.a
MLX_NAME = $(MLX_PATH)libmlx.a

SRC = $(SRC_PATH)draw_map.c $(SRC_PATH)parse_map.c $(SRC_PATH)init.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

MLX_FLAGS = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

INCLUDE_FLAGS = -I $(INCLUDE) -I $(LIBFT_INCLUDE) -I $(MLX_INCLUDE)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(MLX_FLAGS) $(SRC_PATH)main.c $(OBJ_PATH)*.o $(MLX_NAME) $(LIBFT_NAME) -o $(NAME)
	@echo $(C)Compiling [$(NAME)]...$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -Imlx -c $< -o $@
	@printf $(UP)$(CUT)

clean:
	@echo $(R)Cleaning"  "[$(OBJ_PATH)]...$(X)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo $(R)Cleaning" "[$(NAME)]...$(X)
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re