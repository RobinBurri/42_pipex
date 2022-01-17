####################################################################
# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
####################################################################
CC = gcc 

NAME = pipex

FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIBFT		= -L. -lft

MLX_DIR		= mlx
MLX_A		= libmlx.a
MLX			= -L. -lmlx -framework OpenGL -framework AppKit

SRC = src

BIN = bin

SOURCE =  $(SRC)/main.c\
	
			
		
OBJS = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

$(BIN)/%.o : $(SRC)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


help: 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJS)"

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}/
			cp ${LIBFT_DIR}/$(LIBFT_A) .
			$(CC)  ${OBJS} $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
		@rm -f $(OBJS)
		make -C ${LIBFT_DIR} fclean

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT_A)
	
re: fclean all

.PHONY: fclean re all clean bonus