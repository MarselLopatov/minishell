#include "../includes/minishell.h"

static void	env_in_export(char *str)
{
	char	*arg;
	
	ft_putstr_fd("declare -x ", 1);
	while (*str != '=' && *str)
		ft_putchar_fd(*str++, 1);
	arg = ft_strchr(str, '=');
	if (arg)
	{
		ft_putchar_fd('=', 1);
		ft_putchar_fd('\"', 1);
		ft_putstr_fd(arg + 1, 1);
		ft_putchar_fd('\"', 1);
	}
	ft_putchar_fd('\n', 1);
}

static void	print_export()
{
	char	**export;
	int		n;
	int		i;

	n = 0;
	while (info.envp[n])
		n++;
	export = malloc(sizeof(char *) * n);
	if (!export)
		return ;
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

void	add_export(char *new)
{
	char	*name;
	int		size_name;
	int		i;

	i = 0;
	name = get_name(new);
	size_name = ft_strlen(name);
	while (info.envp[i] && name)
	{
		if (!ft_strncmp(info.envp[i], name, size_name) && info.envp[i][size_name] == '=')
		{
			if (new[index_equals(new) + 1] && ft_strchr(new, '='))
			{
				free(info.envp[i]);
				info.envp[i] = ft_strdup(new);
			}
			free(name);
			return ;
		}
		i++;
	}
	info.envp = ft_realloc(info.envp, (i + 1) * sizeof(char *));
	info.envp[i] = new;
	free(name);
}

void	ft_export(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i][0] > 64 && args[i][0] < 91) || (args[i][0] > 96 && args[i][0] < 123))
			add_export(args[i]);
		else
			printf("export: `%s': not a valid identifier\n", args[i]); //error
		i++;
	}
	if (i == 0)
		print_export();
}
