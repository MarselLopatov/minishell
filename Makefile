NAME 			= minishell

HEADER			= includes/minishell.h
PATH_READLINE	= ~/.brew/Cellar/readline/8.1.2/

LIBFT_PATH		= ./libft/
LIBFT			= ./libft/libft.a

OBJ_DIR 		= ./objects
SRC				= $(shell ls ./pipe/*.c) $(shell ls ./src/*.c) main.c
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS 			= -Wall -Wextra -Werror
RM	 			= rm -rf
CC				= gcc

all		: run_lib $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(HEADER)
			$(CC) -o $@ $(OBJ) -I $(HEADER)

run_lib	:
				@make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o:	%.c	$(HEADER)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(RM) $(OBJ)
				@make -C $(LIBFT_PATH) clean

fclean	:		clean
				$(RM) $(NAME) $(OBJ_DIR)
				@make -C $(LIBFT_PATH) fclean

re		:		fclean all

.PHONY	:		all	run_lib clean fclean re