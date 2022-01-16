SRCS	= ft_isalpha.c		\
		  ft_isdigit.c		\
		  ft_isalnum.c 		\
		  ft_isascii.c 		\
		  ft_isprint.c 		\
		  ft_toupper.c 		\
		  ft_tolower.c 		\
		  ft_strlen.c 		\
		  ft_memset.c 		\
		  ft_bzero.c 		\
		  ft_memcpy.c 		\
		  ft_memmove.c 		\
		  ft_strlcpy.c 		\
		  ft_strlcat.c 		\
		  ft_strchr.c 		\
		  ft_strrchr.c 		\
		  ft_strncmp.c 		\
		  ft_memchr.c 		\
		  ft_memcmp.c 		\
		  ft_strnstr.c 		\
		  ft_atoi.c 		\
		  ft_strdup.c		\
		  ft_calloc.c		\
		  ft_substr.c		\
		  ft_strjoin.c		\
		  ft_strtrim.c		\
		  ft_split.c		\
		  ft_itoa.c			\
		  ft_strmapi.c		\
		  ft_striteri.c 	\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl.c		\
		  ft_putnbr_fd.c	\
		  ft_itoa_base16.c		\
		  ft_malloc_ec.c		\
		  ft_free_array.c		\
		  get_next_line.c			\
		  ft_printf.c					\
		  print_char_str.c 				\
		  print_nbr.c 					\
		  print_hexa.c 					\

OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
RM		= rm -f

############################## rules

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib $(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean re

re:			fclean all
