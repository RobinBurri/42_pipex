# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 11:34:55 by rburri            #+#    #+#              #
#    Updated: 2022/01/25 11:34:56 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################################################
# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
####################################################################
CC = gcc 

NAME = pipex

FLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIBFT		= -L. -lft

SRC = src

BIN = bin

SOURCE = 	$(SRC)/main.c\
			$(SRC)/checks.c\
			$(SRC)/path.c\
			$(SRC)/cmds.c\
			$(SRC)/free.c\
	
			
		
OBJS = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

$(BIN)/%.o : $(SRC)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

${NAME}:	${OBJS}
			@make -C ${LIBFT_DIR}/
			@cp ${LIBFT_DIR}/$(LIBFT_A) .
			$(CC)  ${OBJS} $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
		@rm -f $(OBJS)
		@make -C ${LIBFT_DIR} clean

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT_A)
		@make -C ${LIBFT_DIR} fclean
	
re: fclean all

.PHONY: fclean re all clean bonus
