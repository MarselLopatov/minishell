#include "../includes/minishell.h"

void	*ft_realloc(void *old, size_t new_size)
{
	void	*new;
	int		i;

	new = malloc(new_size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		((char *)new)[i] = ((char *)old)[i];
		i++;
	}
	free(old);
	return (new);
}

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