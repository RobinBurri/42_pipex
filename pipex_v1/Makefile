SRCS		= 	main.c			\
				files_check.c 	\
				set_cmd.c 		\
				find_path.c		\

OBJS		= ${SRCS:.c=.o}

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIB			= -L. -lft
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= pipex
RM			= rm -f


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make --silent -C ${LIBFT_DIR}/
			cp ${LIBFT_DIR}/$(LIBFT_A) .
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS} $(LIB)

clean:
			${RM} ${OBJS}
			make --silent -C ${LIBFT_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT_A}
			${RM} ${LIBFT_DIR}/${LIBFT_A}

re:			fclean all

run:		
			./${NAME}

.PHONY:		all clean fclean re run

