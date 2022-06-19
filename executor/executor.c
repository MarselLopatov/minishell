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
		if (execve(data->comand->cmd, data->comand->args, data->envp) == -1)
			; // ERROR
	}
	waitpid(pid, &status, 0);
	// check status child
}

int	one_cmd(t_info *data)
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

void	wait_all_pid(int number_cmd)
{

}

void	fork_all(pid_t *pid, int i)
{
	
	// pid[i] = fork();
	// if (!pid[i])
	
}

int	more_cmd(int number_cmd)
{
	int		i;
	pid_t	*pid_cmd;

	pid_cmd = malloc(sizeof(pid_t) * number_cmd);
	if (!pid_cmd)
		; //error
	i = 0;
	while (i < number_cmd)
	{
		//fork
	}
	wait_all_pid(number_cmd);
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

int	executor(t_info *data)
{
	if (data->comand->next == NULL)
		one_cmd(data);
	else
		more_cmd(count_comand(data->comand));
	// очистка comand в конце работы
	return (1);
}
