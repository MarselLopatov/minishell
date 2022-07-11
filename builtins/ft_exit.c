#include "../includes/minishell.h"

void	ft_exit(char **args)
{
	if (args == NULL)
		ft_putstr_fd("exit\n", 1);
	else if (args[0][0] < 48 || args[0][0] > 57)
	{
		ft_putstr_fd("minishel: exit: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);	
	}
	else if (args[1])
		ft_putstr_fd("minishel: exit: too many arguments ", 2);
	// rl_clear_history();
	//free все
	exit(0);// выбирать статус выхода 
}	