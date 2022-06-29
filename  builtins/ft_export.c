#include "../includes/minishell.h"

void	alph_sorting(char **str, int n)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strncmp(str[i], str[j], ft_strlen(str[i])) > 0)
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	env_in_export(char *str)
{
	char	*arg;
	
	ft_putstr_fd("declare -x ", 1);
	while (*str != '=')
		ft_putchar_fd(*str++, 1);
	ft_putchar_fd('=', 1);
	arg = ft_strchr(str, '=') + 1;
	ft_putchar_fd('\"', 1);
	ft_putstr_fd(arg, 1);
	ft_putchar_fd('\"', 1);
	ft_putchar_fd('\n', 1);

}

void	print_export()
{
	char	**export;
	int		n;
	int		i;

	n = 0;
	while (info.envp[n])
		n++;
	export = malloc(sizeof(char *) * n);
	i = 0;
	while (info.envp[i])
	{
		export[i] = info.envp[i];
		i++;
	}
	alph_sorting(export, n);
	i = 0;
	while (i < n)
		env_in_export(export[i++]);
	free(export);
}

char	*get_name(char *str)
{
	char	*name;
	int		i;
	int		n;

	n = index_equals(str);
	if (n == -1)
		return (str);
	name = malloc(n);
	i = 0;
	while (i < n)
	{
		name[i] = str[i];
		i++;
	}
	return (name);
}

void	add_env(char *new)
{
	char	*name;
	char	*arg;
	int		i;

	i = 0;
	name = get_name(new);
	while (info.envp[i] && name)
	{
		//ffffg ffff
		if (!ft_strncmp(info.envp[i], name, ft_strlen(name)) && info.envp[i][ft_strlen(name)] == '=')
		{
			if (new[index_equals(new) + 1] && ft_strchr(new, '='))
			{
				free(info.envp[i]);
				info.envp[i] = ft_strdup(new);
			}
			return ;
		}
		i++;
	}
	info.envp = ft_realloc(info.envp, (i + 1) * sizeof(char *));
	info.envp[i] = new;
}

void	ft_export(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if ((args[i][0] > 64 && args[i][0] < 91) || (args[i][0] > 96 && args[i][0] < 123))
		{
			add_env(args[i]);
		}
		else
			printf("export: `%s': not a valid identifier\n", args[i]);
		i++;
	}
	print_export();
}
