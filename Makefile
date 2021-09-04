# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 21:06:07 by tschmitt          #+#    #+#              #
#    Updated: 2021/09/04 17:11:47 by tschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang
CCFLAGS = 

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/mlx/

SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC_UTILS_PATH = $(SRC_PATH)utils/
OBJ_UTILS_PATH = $(OBJ_PATH)utils/

INCLUDE = ./include/ 
LIBFT_INCLUDE = $(LIBFT_PATH)include/
MLX_INCLUDE = $(MLX_PATH)

LIBFT_NAME = $(LIBFT_PATH)lib/libft.a
MLX_NAME = $(MLX_PATH)libmlx.a

SRC = $(SRC_PATH)main.c $(SRC_PATH)parse_map.c $(SRC_PATH)validate_map.c \
		$(SRC_PATH)draw_map.c $(SRC_PATH)handle_input.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))
SRC_UTILS = $(SRC_UTILS_PATH)utils.c $(SRC_UTILS_PATH)free_utils.c
OBJ_UTILS = $(patsubst $(SRC_UTILS_PATH)%.c, $(OBJ_UTILS_PATH)%.o, $(SRC_UTILS))

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

$(NAME): $(OBJ) $(OBJ_UTILS) $(LIBFT_NAME) $(MLX_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) $(MLX_FLAGS) $(OBJ) $(OBJ_UTILS) $(LIBFT_NAME) $(MLX_NAME) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)


$(LIBFT_NAME):
	@echo $(Y)Compiling [$(LIBFT_NAME)]...$(X)
	@make -C $(LIBFT_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(LIBFT_NAME)]$(X)

$(MLX_NAME):
	@echo $(Y)Compiling [$(MLX_NAME)]...$(X)
	@make -C $(MLX_PATH)
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$(MLX_NAME)]$(X)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(OBJ_UTILS_PATH)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -Imlx -c $< -o $@
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

$(OBJ_UTILS_PATH)%.o: $(SRC_UTILS_PATH)%.C
	@echo $(Y)Compiling [$@]...$(X)
	@$(CC) $(CCFLAGS) $(INCLUDE_FLAGS) -Imlx -c $< -o $@
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
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