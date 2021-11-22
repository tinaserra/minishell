NAME			=		minishell
CC				=		clang
FLAGS			=		-g -Wall -Werror -Wextra -I $(HEADER) -I $(LIBFT) #-fsanitize=address

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
						$(addprefix ${BUILTINS}, export.c)			\
						$(addprefix ${BUILTINS}, unset.c)			\
						$(addprefix ${BUILTINS}, exit.c)			\
						$(addprefix ${BUILTINS}, utils.c)			\
						$(addprefix ${EXEC}, exec_start.c)			\
						$(addprefix ${EXEC}, exec_utils.c)			\
						$(addprefix ${EXEC}, exec_utils2.c)			\
						$(addprefix ${EXEC}, exec_utils3.c)			\
						$(addprefix ${EXEC}, heredoc.c)				\
						$(addprefix ${PARSING}, commands.c)			\
						$(addprefix ${PARSING}, quotes.c)			\
						$(addprefix ${PARSING}, env.c)				\
						$(addprefix ${PARSING}, redirections.c)		\
						$(addprefix ${PARSING}, start.c)			\
						$(addprefix ${PARSING}, tokens.c)			\
						$(addprefix ${PARSING}, tokens2.c)			\
						$(addprefix ${PARSING}, tokens3.c)			\
						$(addprefix ${PARSING}, utils.c)			\
						$(addprefix ${PROMPT}, env.c)				\
						$(addprefix ${PROMPT}, signal.c)			\
						$(addprefix ${PROMPT}, utils.c)

.c.o:
						@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

OBJS			=		$(SRCS:.c=.o)

all				:		$(NAME)

$(NAME)			:		$(OBJS) $(HEADER)
						@make -C $(LIBFT)
						@$(CC) -o $(NAME) $(FLAGS) $(OBJS) -L$(LIBFT) -lft -lreadline
						@echo "\033[1;31m$(NAME)\033[0;33m created\033[0m"

clean			:
						@rm -rf $(OBJS)
						@make clean -C $(LIBFT)
						@echo "\033[0;33mCleaning minishell: \033[1;31m.o\033[0;33m files\033[0m"

fclean			:		clean
						@rm -f $(NAME)
						@echo "\033[0;33mCleaning minishell: \033[1;31m$(NAME)\033[0m"
						@make fclean -C $(LIBFT)

re				:		fclean all