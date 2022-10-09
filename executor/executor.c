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
	else if (pid == -1)
		;//error fork
	waitpid(pid, &status, 0);
	// status child
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

	fd[0] = dup(0);// read fd
	fd[1] = dup(1);// write fd
	fd[2] = dup(2);// error fd
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
	// signal(SIGINT, SIG_IGN);
	g_info.status = 0;
	signal(SIGINT, SIG_IGN);
	if (data->comand->next == NULL)
		one_cmd(data);
	else
		more_cmd(count_comand(data->comand));
	free_comand(data->comand);
	// signal(SIGINT, SIG_DFL);
	// signal(SIGINT, sigint_handler);
	// signal(SIGQUIT, sigint_handler);
	return (1);
}
