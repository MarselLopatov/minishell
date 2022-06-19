/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:11 by coleta            #+#    #+#             */
/*   Updated: 2022/06/19 20:09:15 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	change(char *pach)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(pach))
	{
		if (pwd)
			; //изменить OLDPWD
			free(pwd);
		pwd = getcwd(NULL, 0);
		if (pwd)
			; //изменить PWD
			free(pwd);
		return (1);
	}
	return (0);
}

void	change_directory(char *pach)
{
	struct stat	st;

	if (change(pach))
		return ;
	// обработка ошибки
	//stat(pach, &st);
}

void	ft_cd(char **args)
{
	if (args[0] == "-")
		;
	if (args[0] == "~")
		;
	//выбор знаков
	// change_directory();
}
