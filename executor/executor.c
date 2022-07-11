/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:08:55 by coleta            #+#    #+#             */
/*   Updated: 2022/06/19 19:29:52 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fork_cmd(t_info *data)
{
	int	pid;
	int	status;

	pid = fork();
	if (!pid)
	{
		chech_comand(data->comand->cmd);// предусмотреть ошибку что команда не нашлась
		if (execve(data->comand->cmd, data->comand->args, data->envp) == -1)
			; // ERROR
	}
	else if (pid == -1)
		;//error fork
	waitpid(pid, &status, 0);
	// check status child
}

void	one_cmd(t_info *data)
{
	// int	fd[3];

	// fd[0] = dup(0);// read fd
	// fd[1] = dup(1);// write fd
	// fd[2] = dup(2);// error fd
	if (ft_builtins(data->comand))
		fork_cmd(data);
	// dup2(fd[0], 0);
	// dup2(fd[1], 1);
	// dup2(fd[2], 2);
}

int	executor(t_info *data)
{
	if (data->comand->next == NULL)
		one_cmd(data);
	else
		more_cmd(count_comand(data->comand));
	free_comand(data->comand);
	return (1);
}
