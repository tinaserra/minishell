NAME			=		minishell
CC				=		gcc
FLAGS			=		-Wall -Werror -Wextra -I $(HEADER) -I $(LIBFT) #-fsanitize=address

HEADER          =		./inc/
PARSING         =		./src/parsing/
PROMPT         	=		./src/prompt/
BUILTINS        =		./src/builtins/
EXEC        	=		./src/execution/
LIBFT           =		./libft/
SRCS            =		src/main.c									\
						src/error.c									\
						$(addprefix ${BUILTINS}, echo.c)			\
						$(addprefix ${BUILTINS}, env.c)				\
						$(addprefix ${BUILTINS}, cd.c)				\
						$(addprefix ${BUILTINS}, pwd.c)				\
						$(addprefix ${EXEC}, start_exec.c)			\
						$(addprefix ${EXEC}, pipi.c)				\
						$(addprefix ${PARSING}, commands.c)			\
						$(addprefix ${PARSING}, quotes.c)			\
						$(addprefix ${PARSING}, env.c)				\
						$(addprefix ${PARSING}, env_replace.c)		\
						$(addprefix ${PARSING}, redirections.c)		\
						$(addprefix ${PARSING}, start.c)			\
						$(addprefix ${PARSING}, tokens.c)			\
						$(addprefix ${PARSING}, tokens2.c)			\
						$(addprefix ${PARSING}, utils.c)			\
						$(addprefix ${PROMPT}, env.c)				\
						$(addprefix ${PROMPT}, signal.c)			\
						$(addprefix ${PROMPT}, utils.c)				\

.c.o:
						@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

OBJS			=		$(SRCS:.c=.o)

all				:		$(NAME)

$(NAME)			:		$(OBJS) $(HEADER)
						@make -C $(LIBFT)
						@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -L$(LIBFT) -lft -lreadline

clean			:
						rm -rf $(OBJS)
						@make clean -C $(LIBFT)

fclean			:		clean
						rm -f $(NAME)
						@make fclean -C $(LIBFT)

re				:		fclean all