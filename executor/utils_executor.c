/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:47:33 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:52:31 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	status_child(int pid)
{
	if (WIFEXITED(pid))
		g_info.status = WEXITSTATUS(pid);
	if (WIFSIGNALED(pid))
	{
		g_info.status = WTERMSIG(pid);
		if (g_info.status != 131)
			g_info.status += 128;
	}
}

void	help_free_cmd(t_comand *comand)
{
	int	i;

	i = 0;
	while (comand->args[i])
	{
		free(comand->args[i]);
		comand->args[i] = NULL;
		i++;
	}
	free(comand->args);
	comand->args = NULL;
}

void	free_comand(t_comand *comand)
{
	t_comand	*temp;

	while (comand != NULL)
	{
		temp = comand;
		if (comand->cmd)
		{
			free(comand->cmd);
			comand->cmd = NULL;
		}
		if (comand->args)
			help_free_cmd(comand);
		comand = comand->next;
		free(temp);
	}
}

int	count_comand(t_comand *comand)
{
	int	i;

	i = 0;
	while (comand != NULL)
	{
		i++;
		comand = comand->next;
	}
	return (i);
}

char	**add_cmd(t_comand *data)
{
	char	**copy;
	int		i;

	i = 0;
	while (data->args[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 2));
	if (!copy)
		return (NULL);
	copy[i + 1] = 0;
	while (i != 0 && data->args[i - 1])
	{
		copy[i] = ft_strdup(data->args[i - 1]);
		i--;
	}
	copy[0] = ft_strdup(data->cmd);
	return (copy);
}
