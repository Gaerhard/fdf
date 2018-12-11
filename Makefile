# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 15:24:01 by gaerhard          #+#    #+#              #
#    Updated: 2018/12/10 18:51:14 by gaerhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = srcs/main.c srcs/parsing.c srcs/events.c srcs/graphic.c srcs/utils.c \
	  srcs/bresenham.c
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
INCLUDES = includes
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
MLXFLAGS = -lmlx -framework OPENgL -framework AppKit
RED := "\033[0;31m"
GREEN := "\033[0;32m"
CYAN := "\033[0;36m"
WHITE :="\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo ${GREEN}"[INFO] Compiled [$(NAME)] executable successfully!"${WHITE}

clean: 
	@rm -Rf $(OBJ)
	@echo ${CYAN}"[INFO] Removed [$(OBJ)] successfully!"${WHITE}

fclean: clean
	@rm -Rf libft/libft.a
	@rm -Rf fillit
	@echo ${CYAN}"[INFO] Removed everything"${WHITE}

re: fclean all

lib:
	@make -C libft

relib:
	@make re -C libft

fclean_lib: fclean
	@make fclean -C libft

.SILENT: $(OBJ)
.PHONY: fclean all clean
