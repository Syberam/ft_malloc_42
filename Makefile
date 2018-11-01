# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 09:39:31 by sbonnefo          #+#    #+#              #
#    Updated: 2018/10/30 18:45:45 by sbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME= libft_malloc_${HOSTTYPE}.so
LINKED_NAME= libft_malloc.so

CC= gcc
FLAG= -shared -Wall -Werror -Wextra -Wpadded
INCS= -I includes
LIBS= -L libft -lft

SRC = $(addprefix $(SRC_PATH)/, alloc_size.c \
	  free.c \
	  give_large.c \
	  give_not_large.c \
	  malloc.c \
	  malloc_init.c \
	  calloc.c \
	  realloc.c)

SRC_PATH= sources

all: libft $(NAME) symlink

libft:
	@make -C libft

norme:
	@echo "\033[30;42m                   NORME SOURCES                  \033[0m"
	@norminette $(SRC_PATH)/*.c
	@echo "\033[30;42m                    NORME .H                      \033[0m"
	@norminette $(INC_PATH)/*.h
	@echo "\033[30;42m                   NORME LIBFT                    \033[0m"

symlink:
	@if [ ! -e ${LINKED_NAME} ]; then \
		/bin/ln -s ${NAME} ${LINKED_NAME}; \
		printf "\e[32m[Symlink created]\e[0m\n"; \
		fi

$(NAME): $(SRC)
	@printf "\e[32m-----------------------------------------------------\e[0m\n"
	@$(CC) $(INCS) $(FLAG) $(SRC) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m-----------------------------------------------------\e[0m\n"

tests: $(NAME)
	@$(CC) -o test0 test/test0.c
	@echo "$(GREEN)compil:$(RESET)\ttest0"
	@$(CC) -o test1 test/test1.c
	@echo "$(GREEN)compil:$(RESET)\ttest1"
	@$(	CC) -o test2 test/test2.c
	@echo "$(GREEN)compil:$(RESET)\ttest2"
	@$(CC) -o test3 test/test3.c
	@echo "$(GREEN)compil:$(RESET)\ttest3"
	@$(CC) -o test3bis test/test3bis.c
	@echo "$(GREEN)compil:$(RESET)\ttest3bis"
	@$(CC) -o test4 test/test4.c
	@echo "$(GREEN)compil:$(RESET)\ttest4"
	@$(CC) -o test5 test/test5.c -L. -lft_malloc 
	@echo "$(GREEN)compil:$(RESET)\ttest5"

clean:
	@make -C libft $@
	@/bin/rm -rf .obj;
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(NAME) $(LINKED_NAME);
	@/bin/rm -f test/unit;
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

.PHONY: clean fclean re libft
