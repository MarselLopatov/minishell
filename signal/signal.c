#include "../includes/minishell.h"

void	sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		// rl_replace_line("", 0);
		rl_redisplay();
	}
}
