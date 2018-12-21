# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 11:40:17 by gaerhard          #+#    #+#              #
#    Updated: 2018/12/21 15:03:07 by gaerhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memccpy.c ft_memcpy.c ft_memset.c ft_bzero.c ft_memmove.c \
	   ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	   ft_putchar_fd.c ft_putchar.c ft_putstr.c ft_putstr_fd.c ft_strlen.c \
	   ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	   ft_strcat.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strchr.c \
	   ft_strstr.c ft_strnstr.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
	   ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strnequ.c ft_strequ.c ft_strsub.c ft_strjoin.c \
	   ft_strtrim.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	   ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_split.c ft_sign.c ft_is_prime.c \
	   ft_dotvect.c ft_abs.c ft_prodvect.c ft_scalevect.c ft_sign.c ft_sqrt.c \
	   ft_sumvect.c ft_setvect.c get_next_line.c ft_lstback.c ft_lstlength.c \
	   ft_print_return.c ft_del.c ft_putnbrendl.c ft_free_return.c
INCLUDES = ../includes
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -O3
RED := "\033[0;31m"
GREEN := "\033[0;32m"
BLUE := "\033[0;34m"
YELLOW := "\033[0;33m"
PURPLE := "\033[0;35m"
WHITE := "\033[0m"

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${YELLOW}"[INFO] Created libft.a successfully!"${WHITE}

clean :
	@/bin/rm -f $(OBJ)
	@echo ${PURPLE}"[INFO] Removed .o from the libft"${WHITE}

fclean : clean
	@/bin/rm -f $(NAME)
	@echo ${PURPLE}"[INFO] Removed .o and libft.a from the libft"${WHITE}

compil : all clean

re : fclean all

.PHONY: re compil fclean clean all
.SILENT: $(OBJ)
