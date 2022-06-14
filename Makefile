NAME 			= minishell

HEADER			= includes/minishell.h
PATH_READLINE	= ~/.brew/Cellar/readline/8.1.2/

OBJ_DIR 		= ./objects
SRC				= $(shell ls ./pipe/*.c) $(shell ls ./src/*.c) $(shell ls ./utils/*.c) main.c
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) $(shell ls ./libft/*.o)

CFLAGS 			= -Wall -Wextra -Werror
RM	 			= rm -rf
CC				= gcc

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(HEADER)
			$(CC) -o $@ $(OBJ) -I $(HEADER)

$(OBJ_DIR)/%.o:	%.c	$(HEADER)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(RM) $(OBJ)

fclean	:		clean
				$(RM) $(NAME) $(OBJ_DIR)

re		:		fclean all

.PHONY	:		all clean fclean re