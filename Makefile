# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:01:12 by tpolonen          #+#    #+#              #
#    Updated: 2022/04/01 14:56:38 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -c -g -Wall -Wextra -Werror -Wpedantic -Wunreachable-code -Wtype-limits -I./include -I../libft/include
LDFLAGS := -L$(LIB_DIR)
LDLIBS := -lft

LIB_DIR = ../libft/
HEADER_DIR = ./include/

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = .

NAME = ft_vec

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)) 
BIN := $(BIN_DIR)/$(NAME)

all: $(NAME)

lib:
	make -C $(LIB_DIR)

$(NAME): lib $(OBJ)
	$(CC) $(OBJ) -o $@.out -L../libft/ -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	/bin/rm -rv $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re lib
