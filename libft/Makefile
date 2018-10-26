# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 18:28:41 by sbonnefo          #+#    #+#              #
#    Updated: 2018/10/26 11:16:26 by sbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_itoa.c \
	  ft_memccpy.c \
	  ft_putendl.c \
	  ft_strcmp.c \
	  ft_strmap.c \
	  ft_strsplit.c \
	  ft_lstadd.c \
	  ft_memchr.c \
	  ft_putendl_fd.c \
	  ft_strcpy.c \
	  ft_strmapi.c \
	  ft_strstr.c \
	  ft_atoi.c \
	  ft_lstdel.c \
	  ft_memcmp.c \
	  ft_putnbr.c \
	  ft_strdel.c \
	  ft_strncat.c \
	  ft_strsub.c \
	  ft_bzero.c \
	  ft_lstdelone.c \
	  ft_memcpy.c \
	  ft_putnbr_fd.c \
	  ft_strdup.c \
	  ft_strnchr.c \
	  ft_strtrim.c \
	  ft_ilen.c \
	  ft_lstiter.c \
	  ft_memdel.c \
	  ft_putstr.c \
	  ft_strequ.c \
	  ft_strncmp.c \
	  ft_tolower.c \
	  ft_isalnum.c \
	  ft_lstlast.c \
	  ft_memmove.c \
	  ft_putstr_fd.c \
	  ft_striter.c \
	  ft_strncpy.c \
	  ft_toupper.c \
	  ft_isalpha.c \
	  ft_lstlen.c \
	  ft_memset.c \
	  ft_putstri.c \
	  ft_striteri.c \
	  ft_strnequ.c \
	  ft_isascii.c \
	  ft_lstmap.c \
	  ft_power.c \
	  ft_strcat.c \
	  ft_strjoin.c \
	  ft_ext_strjoin_free.c \
	  ft_strnew.c \
	  ft_isdigit.c \
	  ft_lstnew.c \
	  ft_putchar.c \
	  ft_strchr.c \
	  ft_strlcat.c \
	  ft_strnstr.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_putchar_fd.c \
	  ft_strclr.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_strrccpy.c \
	  ft_strccpy.c \
	  ft_print_hexa.c

H_DIR = ../includes
INCL = -I $(H_DIR)

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(CC) $(INCL) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -Rf *.h.gch
	@echo "$(NAME) \033[30;42mmade\033[0m"

clean:
	@rm -Rf $(OBJ)
	@echo "\033[3m$(OBJ)\033[30;42mdelete\033[0m"

fclean: clean
	@rm -Rf $(NAME) libft.h.gch
	@echo "$(NAME) \033[30;42m Delete\033[0m\033[0m (Make $@_libft made)"

re: fclean all
