SRCS			=	ft_putstr_fd.c		\
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
					ft_strcmp.c			\
					ft_strcpy.c			\

OBJ_DIR			=	obj
OBJS			=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

NAME			=	libft.a

$(OBJ_DIR)/%o	:	%c
				@mkdir -p $(OBJ_DIR)
				@gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME)			:	${OBJS}
				@ar -rcs ${NAME} ${OBJS}
				@ranlib ${NAME}
				@echo $(NAME) : Created !

all				:	${NAME}

clean			:
				@rm -rf $(OBJ_DIR)
				@rm -f ${OBJS}
				@echo $(OBJ_DIR) : deleted !

fclean			:	clean
				@rm -f ${NAME}
				@echo $(NAME) : deleted !

re				:	fclean all

.PHONY			:	all clean fclean re