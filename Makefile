# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:09:35 by matnusko          #+#    #+#              #
#    Updated: 2025/10/28 17:36:56 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol




SRCS_PATH = src/

INC_PATH = include

OBJ_DIR = obj



SRCS =	\
		$(SRCS_PATH)1_main.c \
		$(SRCS_PATH)2_utils.c \
		$(SRCS_PATH)3_keys.c \
		$(SRCS_PATH)4_init.c \
		$(SRCS_PATH)5_image.c \
		$(SRCS_PATH)6_rendering.c \
		$(SRCS_PATH)7_color.c \
		$(SRCS_PATH)8_help.c \
		$(SRCS_PATH)9_fractols.c \
		


PATH_LIBFT = my_lib

LIBFT = $(PATH_LIBFT)/my_lib.a

PATH_MLX = MLX42

MLX42 = $(PATH_MLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -L/opt/homebrew/lib




CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I $(INC_PATH) -I $(PATH_LIBFT) $(PATH_MLX)/include



OBJS = $(patsubst $(SRCS_PATH)/%.c,$(OBJ_DIR)/%.o,$(SRCS))






########## SCRIPT
all: mlx $(NAME)

$(NAME):  $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $@

$(OBJ_DIR)/%.o: $(SRCS_PATH)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@ $(INCLUDE) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -s -C $(PATH_LIBFT) re
	
mlx:
	@cmake -S $(PATH_MLX) -B $(PATH_MLX)/build
	@cmake --build $(PATH_MLX)/build -j4
	
	
clean:
	rm -rf $(OBJ_DIR)
	make -C $(PATH_LIBFT) clean
	
fclean: clean
	rm -f $(NAME)
	rm -rf $(PATH_MLX)/build
	make -s -C $(PATH_LIBFT) fclean
	
re: fclean all

.PHONY: all clean fclean re

