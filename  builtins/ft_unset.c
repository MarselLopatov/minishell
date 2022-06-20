#include "../includes/minishell.h"

void ft_unset(char **args)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (info.envp[j])
		{
			if (args[i] == info.envp[j])
			{
				k = j;
				while (info.envp[k])
				{
					if (info.envp[k + 1])
						info.envp[k] = info.envp[k + 1];
					k++;
				}
				free(info.envp[k - 1]);
				
			}	
			j++;
		}
		i++;
	}
	
}