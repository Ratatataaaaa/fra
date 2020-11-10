# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 21:41:01 by cwing             #+#    #+#              #
#    Updated: 2020/11/10 19:52:28 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CCFLAGS = -Wall -Wextra -g
FLAGS = -O3

LIBFT = $(LIBFT_DIRECTORY)libft.a
MINILIBX_DIRECTORY = /Library/minilibx_mac
LIBFT_DIRECTORY = ./libft/

LIBRARIES_MAC = -lpthread -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
LIBRARIES_UBUNTU = -lpthread -lm -lft -L$(LIBFT_DIRECTORY) -lmlx -L/usr/include/../lib -lXext -lX11

INCLUDES_DIRECTORY = ./includes/
INCLUDES_DIRECTORY_LIBFT = $(LIBFT_DIRECTORY)includes/
INCLUDES = -I $(INCLUDES_DIRECTORY) -I $(INCLUDES_DIRECTORY_LIBFT)
HEADERS = $(addprefix $(INCLUDES_DIRECTORY), $(HEADERS_LIST))

HEADERS_LIST = fractol.h \
	colorlist.h \
	keyhot.h

SRC_DIRECTORY = ./src/
SRC_LIST = complex_math1.c \
	complex_math2.c \
	complex_math3.c \
	color_list.c \
	init_mlx.c \
	main.c \
	mlx_loop_list.c \
	output_frctl.c \
	pars_frctl.c \
	threads_conf.c \
	zoom_fract.c \
	list_hook.c \
	list_hook2.c \
	put_menu.c \
	color_list2.c
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

OBJ_DIR = objects/
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CCFLAGS) $(FLAGS) $(OBJECTS) -o $(NAME) $(LIBRARIES_MAC) $(INCLUDES)
	@printf "$(GREEN)[$(NAME)] Make executable file $(NAME) successfuly! [OK]\n$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "$(GREEN)[$(NAME)] Make object directory\n$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIRECTORY)%.c $(HEADERS)
	@printf "$(RED)[$(NAME)] Compiling [...]\r$(RESET)"
	@$(CC) $(CCFLAGS) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)[$(NAME)] Compiling [$@]\n$(RESET)"

$(LIBFT):
	@printf "$(GREEN)[$(NAME)] Make $(LIBFT) [OK]\n$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)[$(NAME)] Delete object files successfuly! [OK]\n$(RESET)"


fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@printf "$(RED)[$(NAME)] Delete $(NAME) successfuly! [OK]\n$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
