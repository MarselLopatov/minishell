/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:08:55 by coleta            #+#    #+#             */
/*   Updated: 2022/06/18 18:08:58 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fork_cmd()
{
	
	// fork
	// signal
	waitpid(NULL, NULL, NULL);
}

int	one_cmd()
{
	// int	fd[3];

	// fd[0] = dup(0);// read fd
	// fd[1] = dup(1);// write fd
	// fd[2] = dup(2);// error fd
	fork_cmd();
	// dup2(fd[0], 0);
	// dup2(fd[1], 1);
	// dup2(fd[2], 2);
}

void	wait_all_pid(int number_cmd)
{

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

int	count_comand()
{
	int	i;

	i = 0;
	while (i)
	{
		i++;
	}
	return (i);
}

int	executor()
{
	int	number_cmd;

	number_cmd =  count_comand();
	if (number_cmd == 1)
		one_cmd(); // one
	else if (number_cmd > 1)
		more_cmd(number_cmd); // more one
	// очистка comand в конце работы
	return (1);
}
