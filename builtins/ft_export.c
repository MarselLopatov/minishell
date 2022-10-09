/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:54:11 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:55:25 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (g_info.envp[n] && g_info.envp)
		n++;
	export = malloc(sizeof(char *) * n);
	if (!export)
		return ;
	i = 0;
	while (i < n)
	{
		export[i] = g_info.envp[i];
		i++;
	}
	alph_sorting(export, n);
	i = 0;
	while (i < n)
		env_in_export(export[i++]);
	free(export);
}

void	init_p(int *size_name, int *i, char **name, char *new)
{
	*i = 0;
	*name = get_name(new);
	*size_name = ft_strlen(*name);
}

void	add_export(char *new)
{
	char	*name;
	int		size_name;
	int		i;

	name = NULL;
	init_p(&size_name, &i, &name, new);
	printf(":%s\n", name);
	while (g_info.envp[i] && name)
	{
		if (!ft_strncmp(g_info.envp[i], name, size_name) \
		&& (g_info.envp[i][size_name] == '=' \
			|| g_info.envp[i][size_name] == '\0'))
		{
			if (new[index_equals(new) + 1] && ft_strchr(new, '='))
			{
				free(g_info.envp[i]);
				g_info.envp[i] = ft_strdup(new);
			}
			free(name);
			return ;
		}
		i++;
	}
	g_info.envp = ft_realloc(g_info.envp, i * sizeof(char *), \
							(i + 2) * sizeof(char *));
	g_info.envp[i] = ft_strdup(new);
	free(name);
}

static int	valid_args(char	*str)
{
	int	i;

	if (!((str[0] > 64 && str[0] < 91) || (str[0] > 96 && str[0] < 123) || \
				str[0] == 95))
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
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
		i++;
	}
	if (i == 0)
		print_export();
}
