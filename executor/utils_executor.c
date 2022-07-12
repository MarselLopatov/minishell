#include "../includes/minishell.h"

void	free_comand(t_comand *comand)
{
	t_comand	*temp;
	int			i;

	i = 0;
	while (comand != NULL)
	{
		temp = comand;
		free(comand->cmd);
		comand->cmd = NULL;
		while (comand->args[i])
		{
			free(comand->args[i]);
			comand->args[i] = NULL;
			i++;
		}
		free(comand->args);
		comand->args = NULL;
		// free(comand->redirect_in);
		// free(comand->redirect_out);
		comand = comand->next;
		free(temp);
	}
}

int	count_comand(t_comand *comand)
{
	int	i;

	i = 0;
	while (comand != NULL)
	{
		i++;
		comand = comand->next;
	}
	return (i);
}
