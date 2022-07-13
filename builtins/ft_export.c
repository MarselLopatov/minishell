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

static void	print_export(void)
{
	char	**export;
	int		n;
	int		i;

	n = 0;
	while (info.envp[n] && info.envp)
		n++;
	export = malloc(sizeof(char *) * n);
	if (!export)
		return ;
	i = 0;
	while (i < n)
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
	name = get_name(new);// можно без malloc !!!
	size_name = ft_strlen(name);
	while (info.envp[i] && name)
	{
		if (!ft_strncmp(info.envp[i], name, size_name) \
		&& (info.envp[i][size_name] == '=' || info.envp[i][size_name] == '\0') )
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
	info.envp = ft_realloc(info.envp, i * sizeof(char *), (i + 2) * sizeof(char *));
	info.envp[i] = ft_strdup(new);
	free(name);
}
// "" проверить 
static int	valid_args(char	*str)
{
	int	i;

	if (!((str[0] > 64 && str[0] < 91) || (str[0] > 96 && str[0] < 123) || str[0] == 95))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] > 64 && str[i] < 91) || \
		(str[i] > 96 && str[i] < 123) || \
		(str[i] > 47 && str[i] < 58) || str[i] == 95))
			return (0);
		i++;
	}
	return (1);
}

void	ft_export(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		printf("args[%d] = %s\n", i, args[i]);
		if (valid_args(args[i]))
			add_export(args[i]);
		else
			printf("export: `%s': not a valid identifier\n", args[i]); //error
		i++;
	}
	if (i == 0)
		print_export();
}
