# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kain2250 <kain2250@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 21:57:42 by cwing             #+#    #+#              #
#    Updated: 2020/11/09 03:40:15 by kain2250         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra  -c
INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS_LIST = libft.h\
	get_next_line.h\
	get_next_line2.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = ft_atoi.c\
	ft_atoi_base.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c \
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c \
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c \
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c \
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c \
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c \
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c \
	ft_binar_chr.c\
	ft_lst_push_back.c\
	ft_strlowcase.c\
	ft_max.c\
	ft_min.c\
	ft_strhighcase.c \
	get_next_line.c\
	get_next_line2.c\
	ft_lstdelitem.c\
	ft_strjoin_free.c\
	ft_strspleet1.c\
	ft_free_split.c \
	ft_percent.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(HEADERS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "$(GREEN)[$(NAME)] Compiling successfuly! [OK]\n"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@printf "$(GREEN)[$(NAME)] Make OBG dir $(OBJECTS_DIRECTORY) successfuly! [OK]\n"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	@printf "$(RED)[$(NAME)] Compiling [...]\r"
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@printf "$(GREEN)[$(NAME)] Compiling [$@]\n$(RESET)"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@printf "$(RED)[$(NAME)] Delete object files successfuly! [OK]\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[$(NAME)] Delete library $(NAME) successfuly! [OK]\n"
	

re:
	@$(MAKE) fclean
	@$(MAKE) all