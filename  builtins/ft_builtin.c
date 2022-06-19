/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:34:24 by coleta            #+#    #+#             */
/*   Updated: 2022/06/19 16:35:51 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	get_comand(t_comand *comand)
{
	int			i;
	const char	*comands[] = {"echo", "env", "pwd", "cd", "exit", "export",
		"unset", "history", NULL};

	i = 0;
	while (comands[i])
	{
		if (comand->cmd == comands[i]) // !!!
			return (i);
		i ++;
	}
	return (-1);
}

static void	*init_commnds(void)
{
	void	(**command)(char **);

	command = malloc(sizeof(void *) * 8);
	// command[0] = ft_echo;
	// command[1] = ft_env;
	// command[2] = ft_pwd;
	// command[3] = ft_cd;
	// command[4] = ft_exit;
	// command[5] = ft_export;
	// command[6] = ft_unset;
	// command[7] = ft_history;
	return (command);
}

int	ft_builtins(t_comand *comand)
{
	int		i;
	void	(**command)(char **);

	command = init_commnds();
	i = get_comand(comand);
	if (i > -1)
	{
		command[i](comand->args);
		free(comand);
		return (0);
	}
	free(comand);
	return (1);
}