SRCS			=	main.c			\
					parsing_start.c	\
					signal.c		\
					env.c			\
					history.c		\
					termcaps.c		\
					echo.c			\
					env_builtin.c	\
					env_replace.c	\

SRCS_TINA		=	main.c			\
					parsing_start.c	\
					signal.c		\
					env.c			\
					history.c		\
					termcaps.c		\
					echo.c			\
					env_builtin.c	\
					env_replace.c	\

SRCS_JOHN		=	main.c			\
					john.c			\
					signal.c		\
					env.c			\
					history.c		\
					termcaps.c		\
					echo.c			\
					env_builtin.c	\

NAME			=	minishell
NAME_JOHN		=	minijohn
NAME_TINA		=	minitina

OBJ_DIR			=	obj
SRC_DIR			=	src
INC_DIR			=	inc
LIBFT_DIR		=	libft
LIBFT			=	libft.a

# override -> permet de reecrire la suite de la variable
override FLAGS	+=	-Wall -Wextra -Werror -MMD -O3 #-fsanitize=address

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
OBJ_TINA		=	$(addprefix $(OBJ_DIR)/,$(SRCS_TINA:.c=.o))
OBJ_JOHN		=	$(addprefix $(OBJ_DIR)/,$(SRCS_JOHN:.c=.o))
DPD				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))


# -C faire make comme si on etait dans le dossier
# -j multisreder / ameliore la vitesse de compliation
# Pas de regle opti car makefile mlx pas compatible
all				:
				@$(MAKE) -C $(LIBFT_DIR)
				@$(MAKE) -j $(NAME)

$(NAME)			:	$(OBJ)
				@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -l ft -ltermcap
				@echo $(NAME) : Created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) | .gitignore
				@mkdir -p $(OBJ_DIR)
				@gcc $(FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -c $< -o $@

.gitignore		:
				@echo $(NAME) > .gitignore

debug			:	fclean
				make all CFLAGS:="-DDEBUG -g"

john			:	$(OBJ_JOHN)
				@$(MAKE) -C $(LIBFT_DIR)
				@clang $(FLAGS) -o $(NAME_JOHN) $(OBJ_JOHN) -L $(LIBFT_DIR) -l ft -ltermcap
				@echo $(NAME_JOHN) : Souris John !!

tina			:	$(OBJ_TINA)
				@$(MAKE) -C $(LIBFT_DIR)
				@gcc $(FLAGS) -o $(NAME_TINA) $(OBJ_TINA) -L $(LIBFT_DIR) -l ft -ltermcap
				@echo $(NAME_TINA) : Le temps est bon, le ciel est bleu !

clean			:
				@$(MAKE) clean -C $(LIBFT_DIR)
				@rm -rf $(OBJ_DIR)
				@echo "obj deleted"

fclean			:	clean
				@rm -rf $(LIBFT_DIR)/$(LIBFT)
				@echo "[$(LIBFT)]: deleted"
				@rm -rf $(NAME)
				@echo "[$(NAME)]: deleted"

re				: fclean all

.PHONY			: all, clean, fclean, re

# Utilise les .d (et ignore s'ils n'existe pas)
 -include $(DPD)