NAME 			= minishell

HEADER			= includes/minishell.h
PATH_READLINE	= ~/.brew/Cellar/readline/8.1.2/

OBJ_DIR 		= ./objects
SRC				= $(shell ls ./pipe/*.c) $(shell ls ./src/*.c) $(shell ls ./utils/*.c) $(shell ls ./lexer/*.c) main.c
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS 			= -Wall -Wextra -Werror
RM	 			= rm -rf
CC				= gcc

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(HEADER)
			$(CC) -o $@ $(OBJ) -lreadline -L $(PATH_READLINE)lib -I $(HEADER)

$(OBJ_DIR)/%.o:	%.c	$(HEADER)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(RM) $(OBJ)

fclean	:		clean
				$(RM) $(NAME) $(OBJ_DIR)

re		:		fclean all

.PHONY	:		all clean fclean re