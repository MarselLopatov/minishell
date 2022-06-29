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
	// declare -x Name="1"
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

void	ft_export(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		i++;
	}
	if (i == 0)
		print_export();
}
