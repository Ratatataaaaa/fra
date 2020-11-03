# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwing <cwing@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 21:41:01 by bdrinkin          #+#    #+#              #
#    Updated: 2020/11/03 19:15:14 by cwing            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Флаги компиляции:
CC = gcc
CCFLAGS = -Wall -Wextra  -g
FLAGS = -O0

# Список библиотек и их пути:
LIBFT = $(LIBFT_DIRECTORY)libft.a
MINILIBX_DIRECTORY = /usr/local/lib/
LIBFT_DIRECTORY = ./libft/

# Флаги для сборки библиотек
LIBRARIES_MAC = -lpthread -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
LIBRARIES_UBUNTU = -lpthread -lm -lft -L$(LIBFT_DIRECTORY) -L /usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

# Заголовочные файлы и их пути:
INCLUDES_DIRECTORY = ./includes/
INCLUDES_DIRECTORY_LIBFT = $(LIBFT_DIRECTORY)includes/
INCLUDES = -I $(INCLUDES_DIRECTORY) -I $(INCLUDES_DIRECTORY_LIBFT)
HEADERS = $(addprefix $(INCLUDES_DIRECTORY), $(HEADERS_LIST))
HEADERS_LIST = fractol.h \
	colorlist.h \
	keyhot.h
	
# Основные файлы программы и их пути:
SRC_DIRECTORY = ./src/
SRC_LIST = complex_penitrator.c \
	complex_penitrator1.c \
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

# Объектные файлы и их пути:
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))

# Определение цвета вывода:
GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

# Лабуда-бу-даб-даб
.PHONY: all clean fclean re OBJ_CREATE

# Основные правила сборки:
all: $(NAME)

$(NAME): $(LIBFT) OBJ_CREATE
	@echo "\n$(NAME): $(GREEN)Создание исполняемого файла$(RESET)"
	@$(CC) $(CCFLAGS) $(FLAGS) $(OBJECTS) -o $(NAME) $(LIBRARIES_MAC) $(INCLUDES)
	@echo "$(NAME): $(GREEN)Готово$(RESET)"

$(OBJ_DIR):
	@echo "$(NAME): $(GREEN)Создание объектных файлов$(RESET)"
	@mkdir -p $(OBJ_DIR)

OBJ_CREATE: $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(FLAGS) -c $(INCLUDES) $(SRC)
	@mv $(OBJ_LIST) $(OBJ_DIR)
	@echo "$(OBJ_DIR): $(GREEN)Готово$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Создание $(LIBFT)$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)Объектные файлы удалены$(RESET)"


fclean: clean
	@rm -f $(LIBFT)
	@# @echo "$(NAME): $(RED)$(LIBFT)Удалено$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME)Удалено$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
