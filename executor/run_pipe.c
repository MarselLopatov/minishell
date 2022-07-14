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
	signal(SIGINT, SIG_DFL);
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
		chech_comand(data);// предусмотреть ошибку что команда не нашлась
		data->args = add_cmd(data);
		if (execve(data->args[0], data->args, info.envp) == -1)
			printf("comand dont work\n");//Ошибка execve
	}
	exit(0);
}

int	more_cmd(int number_cmd)
{
	t_comand	*temp;
	pid_t		*pid;
	int			i;

	temp = info.comand;	
	i = 0;
	pid = malloc(sizeof(pid_t) * number_cmd);
	if (!pid)
		printf("MALLOC ERROR\n");//error pid malloc
	while (i < number_cmd)
	{
		pid[i] = fork();
		if (!pid[i])
			baby_process(temp);
		else if (pid[i] == -1)
			;//error fork
		if (temp->fd_in_out[WRITE_FD] != STDOUT_FILENO)
			close(temp->fd_in_out[WRITE_FD]);
		if (temp->fd_in_out[READ_FD] != STDIN_FILENO)
			close(temp->fd_in_out[READ_FD]);
		i++;
		temp = temp->next;
	}
	wait_pid(pid, number_cmd);
	free(pid);
	return (0);
}
