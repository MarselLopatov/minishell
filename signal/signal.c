#include "../includes/minishell.h"

// void	sigint_handler(int sign_num)
// {
// 	if (sign_num == SIGINT)
// 	{
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		rl_on_new_line();
// 		// rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// }

// static void	process(int sign_num)
// {
// 	if (!kill(g_info.pid, sign_num))
// 	{
// 		if (sign_num == SIGQUIT)
// 		{
// 			ft_putstr_fd("Quit: 3\n", 1);
// 			g_info.status = 131;
// 		}
// 		else if (sign_num == SIGINT)
// 		{
// 			ft_putstr_fd("\n", 1);
// 			g_info.status = 130;
// 		}
// 	}
// 	else if (sign_num == SIGINT)
// 	{
// 		ft_putchar_fd('\n', 1);
// 		g_info.status = 1;
// 	}
// }




// void	sigint_handler(int sign_num)
// {	
// 	// if ((sign_num == SIGINT || sign_num == SIGQUIT) && g_info.pid != 0)
// 	// 	process(sign_num);
// 	// else
// 	// {
// 		if (sign_num == SIGINT)
// 		{
// 			// g_info.status = 1;
// 			rl_on_new_line();
// 			rl_redisplay();
// 			ft_putstr_fd("  ", 1);
// 			ft_putstr_fd("\n", 1);
// 			rl_on_new_line();
// 			rl_replace_line("", 1);
// 			rl_redisplay();
// 		}
// 		else if (sign_num == SIGQUIT)
// 		{
// 			rl_on_new_line();
// 			rl_redisplay();
// 			ft_putstr_fd("  \b\b", 1);
// 		}
// 	// }
// }

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}

int	accept_signals(void)
{
	if (signal(SIGINT, &handler) == SIG_ERR)
		return 1;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return 1;
	return (0);
}

// void	handler_heredoc(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		exit(1);
// 	}
// }
