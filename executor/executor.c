/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:08:55 by coleta            #+#    #+#             */
/*   Updated: 2022/10/09 14:52:59 by cdoria           ###   ########.fr       */
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
		signal(SIGINT, SIG_DFL);
		chech_comand(data->comand);
		data->comand->args = add_cmd(data->comand);
		if (execve(data->comand->args[0], data->comand->args, g_info.envp) == -1)
		{
			printf("comand dont work a[0] = %s\ta[1] = %s\n", \
				data->comand->args[0],data->comand->args[1]);
			exit(127);
		}
	}
	waitpid(pid, &status, 0);
	status_child(status);
}

void	set_redir(int *end)
{
	dup2(end[READ_FD], STDIN_FILENO);
	dup2(end[WRITE_FD], STDOUT_FILENO);
	dup2(end[ERR_FD], STDERR_FILENO);
}

void	one_cmd(t_info *data)
{
	int	fd[3];

	fd[0] = dup(0);
	fd[1] = dup(1);
	fd[2] = dup(2);
	set_redir(data->comand->fd_in_out);
	if (ft_builtins(data->comand))
		fork_cmd(data);
	close(data->comand->fd_in_out[0]);
	close(data->comand->fd_in_out[1]);
	close(data->comand->fd_in_out[2]);
	set_redir(fd);
}

int	executor(t_info *data)
{
	g_info.status = 0;
	signal(SIGINT, SIG_IGN);
	if (data->comand->next == NULL)
		one_cmd(data);
	else
		more_cmd(count_comand(data->comand));
	free_comand(data->comand);
	return (1);
}
