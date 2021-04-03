SRCS		=	ft_putstr_fd.c		\
				ft_strtrim.c		\
				ft_bzero.c			\
				ft_split.c			\
				ft_strdup.c			\
				ft_strchr.c			\
				ft_substr.c			\
				ft_strlen.c			\
				get_next_line.c 	\
				ft_itoa.c			\
				ft_strs_tab_size.c	\
				ft_strncmp.c		\
				ft_isdigit.c		\
				ft_strjoin.c		\
				ft_calloc.c			\
				ft_memcpy.c			\
				ft_realloc.c		\

OBJS		=	${SRCS:.c=.o}

NAME		=	libft.a

.c.o		:
			gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re