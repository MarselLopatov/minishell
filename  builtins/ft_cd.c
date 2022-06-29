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
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(name);
	while (info.envp[i])
	{
		if (!ft_strncmp(info.envp[i], name, len))
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
		// ft_strncmp
	if (!ft_strncmp(args[0], "-", 2))
	{
		// проверка OLDPWD из ENV
		change_directory(ft_strchr(get_env("OLDPWD"), '=') + 1);
		//print PWD
	}
	else if (!ft_strncmp(args[0], "~", 1) || !ft_strncmp(args[0], "--", 3))
	{
		// проверка HOME из ENV
		change_directory(ft_strchr(get_env("HOME"), '=') + 1);
		if (!ft_strncmp(args[0], "~/", 2))
			change_directory(args[0] + 2);
	}
	else
		change_directory(args[0]);
}
