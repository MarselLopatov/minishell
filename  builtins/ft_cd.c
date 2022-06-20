/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:11 by coleta            #+#    #+#             */
/*   Updated: 2022/06/20 20:02:17 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env(char *name)
{
	int	i;

	i = 0;
	while (info.envp[i])
	{
		if (info.envp[i] == name)
			return (info.envp[i]);
		i++;
	}
	return (NULL);
}

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
	if (args[0] && args[1])
		; //ERROR Many args
	if (args[0] == "-")
	{
		// проверка OLDPWD из ENV
		change_directory(ft_strchr(get_env("OLDPWD"), '=') + 1);
		//print PWD
	}
	else if (args[0] == "~" || args[0] == "--")
	{
		// проверка HOME из ENV
		change_directory(ft_strchr(get_env("HOME"), '=') + 1);
		if (args[0] == "~/")
			change_directory(args[0] + 2);
	}
	else
		change_directory(args[0]);
}
