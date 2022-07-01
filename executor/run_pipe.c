#include "../includes/minishell.h"

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
	{
		chech_comand(data->cmd);// предусмотреть ошибку что команда не нашлась
		if (execve(data->cmd, data->args, info.envp) == -1)
			;//Ошибка execve
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
	cmds_fds(info.comand, number_cmd);//в init 
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
