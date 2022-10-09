/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:49:18 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:56:43 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	index_equals(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

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

char	*get_name(char *str)
{
	char	*name;
	int		i;
	int		n;

	n = index_equals(str);
	if (n == -1)
		n = ft_strlen(str);
	name = malloc(n);
	if (!name)
		return (NULL);
	i = 0;
	while (i < n)
	{
		name[i] = str[i];
		i++;
	}
	return (name);
}

char	*get_env(char *name)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name);
	while (g_info.envp[i])
	{
		if (!ft_strncmp(g_info.envp[i], name, len) && g_info.envp[i][len] == '=')
			return (g_info.envp[i]);
		i++;
	}
	return (NULL);
}

void	set_env(char *name, char *pach)
{
	char	*env;

	env = ft_strjoin(name, pach);
	add_export(env);
	free(env);
}
