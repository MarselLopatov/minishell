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

void	define_fds(t_comand *cmds)
{
	int	end[2];

	pipe(end);
	if (cmds[0].fd_in_out[WRITE_FD] == STDOUT_FILENO)
		cmds[0].fd_in_out[WRITE_FD] = end[WRITE_FD];
	else
		close(end[WRITE_FD]);
	if (cmds[1].fd_in_out[READ_FD] == STDIN_FILENO)
		cmds[1].fd_in_out[READ_FD] = end[READ_FD];
	else
		close(end[READ_FD]);
	if (cmds[0].fd_close[0] == -1)
		cmds[0].fd_close[0] = cmds[1].fd_in_out[READ_FD];
	else
		cmds[0].fd_close[1] = cmds[1].fd_in_out[READ_FD];
	if (cmds[1].fd_close[0] == -1)
		cmds[1].fd_close[0] = cmds[0].fd_in_out[WRITE_FD];
	else
		cmds[1].fd_close[1] = cmds[0].fd_in_out[WRITE_FD];
}

void	cmds_fds(t_comand *cmds, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((size != 1) && (i != size - 1))
			define_fds(&cmds[i]);
		if (i == size - 1 && (size != 1))
			cmds[i].fd_close[0] = cmds[i - 1].fd_in_out[WRITE_FD];
		i++;
	}
}

void	fork_cmd(t_info *data)
{
	int	pid;
	int	status;

	pid = fork();
	if (!pid)
		if (execve(data->comand->cmd, data->comand->args, data->envp) == -1)
			; // ERROR
	else if (pid == -1)
		;//error fork
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

void	baby_process(t_comand *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data->fd_close[i] > 0)
			close(data->fd_close[i]);
		i++;
	}
	dup2(data->fd_in_out[READ_FD], STDIN_FILENO);
	dup2(data->fd_in_out[WRITE_FD], STDOUT_FILENO);
	dup2(data->fd_in_out[ERR_FD], STDERR_FILENO);
	if (ft_builtins(data))
		if (execve(data->cmd, data->args, info.envp) == -1)
			;//Ошибка execve
	}

void	wait_pid(pid_t *pid, int n)
{
	int	status;
	int	i;

	i = 0;
	while (i < n)
	{
		if (pid[i])
			waitpid(pid[i], &status, 0);
		i++;
	}
	
}

int	more_cmd(int number_cmd)
{
	int		i;
	pid_t	*pid;

	i = 0;
	pid = malloc(sizeof(pid_t) * number_cmd);
	if (!pid)
		;//error pid malloc
	cmds_fds(info.comand, number_cmd);
	while (i < number_cmd)
	{
		pid[i] = fork();
		if (!pid[i])
			baby_process(&info.comand[i]);
		else if (pid[i] == -1)
			;//error fork
		if (info.comand[i].fd_in_out[WRITE_FD] != STDOUT_FILENO)
			close(info.comand[i].fd_in_out[WRITE_FD]);
		if (info.comand[i].fd_in_out[READ_FD] != STDIN_FILENO)
			close(info.comand[i].fd_in_out[READ_FD]);
		// int status;
		// waitpid(pid, &status, 0);
		i++;
	}
	wait_pid(pid, number_cmd);
	free(pid);
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
