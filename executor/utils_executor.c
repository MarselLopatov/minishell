#include "../includes/minishell.h"

void	free_comand(t_comand *comand)
{
	t_comand	*temp;
	int			i;

	i = 0;
	while (comand != NULL)
	{
		temp = comand;
		if (comand->cmd)
		{
			free(comand->cmd);
			comand->cmd = NULL;
		}
		if (comand->args)
		{
			while (comand->args[i])
			{
				free(comand->args[i]);
				comand->args[i] = NULL;
				i++;
			}
			free(comand->args);
			comand->args = NULL;
		}
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

char	**add_cmd(t_comand *data)
{
	char	**copy;
	int		i;

	i = 0;
	while (data->args[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 2));
	copy[i + 1] = 0;
	while (data->args[i - 1])
	{
		copy[i] = data->args[i - 1];
		i--;
	}
	copy[i] = data->cmd;
	// free(data->args);
	return(copy);
}
