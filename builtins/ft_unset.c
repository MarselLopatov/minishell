#include "../includes/minishell.h"

static void	up_mass(int k)
{
	while (info.envp[k + 1])
	{
		info.envp[k] = info.envp[k + 1];
		k++;
		if (!info.envp[k + 1])
			info.envp[k] = NULL;
	}
	info.envp = ft_realloc(info.envp, (k + 1) * sizeof(char *), \
							(k + 2) * sizeof(char *));
}

static int	valid_args(char	*str)
{
	int	i;

	if (!((str[0] > 64 && str[0] < 91) || (str[0] > 96 && str[0] < 123) \
			|| str[0] == 95))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!((str[i] > 64 && str[i] < 91) || \
		(str[i] > 96 && str[i] < 123) || \
		(str[i] > 47 && str[i] < 58) || str[i] == 95))
			return (0);
		i++;
	}
	return (1);
}

void	dell(char	*arg)
{
	char	*temp;
	int		j;

	j = 0;
	if (!valid_args(arg))
	{
		ft_putstr_fd("unset: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else
	{
		while (info.envp[j])
		{
			if (!ft_strncmp(info.envp[j], arg, ft_strlen(arg)))
			{
				temp = info.envp[j];
				info.envp[j] = NULL;
				up_mass(j);
				free(temp);
			}	
			j++;
		}
	}
}

void	ft_unset(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		dell(args[i]);
		i++;
	}
}
