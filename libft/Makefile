SRCS			=	ft_putstr_fd.c \
					ft_strtrim.c \
					ft_bzero.c \
					ft_split.c \
					ft_strdup.c \
					ft_strchr.c \
					ft_substr.c \
					ft_strlen.c \
					get_next_line.c \
					ft_itoa.c \
					ft_strs_tab_size.c \
					ft_strncmp.c \
					ft_isdigit.c \
					ft_strjoin.c \
					ft_calloc.c \
					ft_memcpy.c \
					ft_realloc.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_putnbr_fd.c \
					ft_swap.c \
					ft_rev_int_tab.c \
					ft_sort_int_tab.c \
					ft_putchar_fd.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_putstr_non_printable.c \
					ft_check_base.c \
					ft_putnbr_base.c \
					ft_atoi_base.c \
					ft_itoa_base.c \
					ft_convert_base.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c

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