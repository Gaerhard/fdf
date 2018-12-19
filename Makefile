# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 15:24:01 by gaerhard          #+#    #+#              #
#    Updated: 2018/12/19 18:35:53 by gaerhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = srcs/main.c srcs/parsing.c srcs/events.c srcs/graphic.c srcs/utils.c \
	  srcs/bresenham.c srcs/rotation.c srcs/scale.c srcs/utils2.c srcs/events2.c
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
INCLUDES = includes
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES) -O3
MLXFLAGS = -lmlx -framework OPENgL -framework AppKit
RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
RESET :="\033[0m"

all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"${RESET}

clean: 
	@rm -Rf $(OBJ)
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] successfully!"${RESET}

fclean: clean
	@rm -Rf libft/libft.a
	@rm -Rf fillit
	@echo ${CYAN}"[INFO] Removed everything"${RESET}

re: fclean all

lib:
	@make -C libft

relib:
	@make re -C libft

fclean_lib: fclean
	@make fclean -C libft

.SILENT: $(OBJ) $(LIB)
.PHONY: fclean all clean lib relib fclean_lib
