NAME			=		minishell
CC				=		gcc
FLAGS			=		-Wall -Werror -Wextra -I $(HEADER) -I $(LIBFT) -Wunused-function #-fsanitize=address

HEADER          =		./inc/
PARSING         =		./src/parsing/
PROMPT         	=		./src/prompt/
BUILTINS        =		./src/builtins/
LIBFT           =		./libft/
SRCS            =		src/main.c									\
						$(addprefix ${BUILTINS}, echo.c)			\
						$(addprefix ${BUILTINS}, env.c)				\
						$(addprefix ${BUILTINS}, cd.c)				\
						$(addprefix ${BUILTINS}, pwd.c)				\
						$(addprefix ${PARSING}, commands.c)			\
						$(addprefix ${PARSING}, env_replace.c)		\
						$(addprefix ${PARSING}, start.c)			\
						$(addprefix ${PARSING}, tokens.c)			\
						$(addprefix ${PARSING}, tokens2.c)			\
						$(addprefix ${PARSING}, utils.c)			\
						$(addprefix ${PROMPT}, env.c)				\
						$(addprefix ${PROMPT}, history.c)			\
						$(addprefix ${PROMPT}, signal.c)			\
						$(addprefix ${PROMPT}, termcaps.c)			\
						$(addprefix ${PROMPT}, utils.c)				\

.c.o:
						@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

OBJS			=		$(SRCS:.c=.o)

all				:		$(NAME)

$(NAME)			:		$(OBJS) $(HEADER)
						@make -C $(LIBFT)
						@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -L$(LIBFT) -lft -ltermcap

clean			:
						rm -rf $(OBJS)
						@make clean -C $(LIBFT)

fclean			:		clean
						rm -f $(NAME)
						@make fclean -C $(LIBFT)

re				:		fclean all