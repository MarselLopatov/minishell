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
		chech_comand(data->comand);// предусмотреть ошибку что команда не нашлась
		data->comand->args = add_cmd(data->comand);
		if (execve(data->comand->args[0], data->comand->args, info.envp) == -1)
			printf("comand dont work a[0] = %s\ta[1] = %s\n", data->comand->args[0],data->comand->args[1]);//Ошибка execve
	}
	else if (pid == -1)
		;//error fork
	waitpid(pid, &status, 0);
	// check status child
}

// void	set_redir(int *end)
// {
// 	dup2(end[READ_FD], STDIN_FILENO);
// 	dup2(end[WRITE_FD], STDOUT_FILENO);
// 	dup2(end[ERR_FD], STDERR_FILENO);
// }

void	one_cmd(t_info *data)
{
	// int	fd[3];

	// fd[0] = dup(0);// read fd
	// fd[1] = dup(1);// write fd
	// fd[2] = dup(2);// error fd
	// set_redir(data->comand->fd_in_out);
	if (ft_builtins(data->comand))
		fork_cmd(data);
	// dup2(fd[0], 0);
	// dup2(fd[1], 1);
	// dup2(fd[2], 2);
	// set_redir(fd);
}

int	executor(t_info *data)
{
	// signal(SIGINT, SIG_IGN);
	if (data->comand->next == NULL)
		one_cmd(data);
	else
		more_cmd(count_comand(data->comand));
	free_comand(data->comand);
	// signal(SIGINT, SIG_DFL);
	return (1);
}
