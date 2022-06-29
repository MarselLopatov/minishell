#include "../includes/minishell.h"

static void	up_mass(int k)
{
	while (info.envp[k + 1])
	{
		info.envp[k] = info.envp[k + 1];
		k++;
		if (!info.envp[k + 1])
		{
			free(info.envp[k]);
			info.envp[k] = NULL;
		}
	}
	info.envp = ft_realloc(info.envp, (k - 1) * sizeof(char *));
}

void ft_unset(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (info.envp[j])
		{
			if (args[i] == info.envp[j])
			{
				temp = info.envp[j];
				info.envp[j] = NULL;
				up_mass(j);
				free(temp);
			}	
			j++;
		}
		i++;
	}
	
}