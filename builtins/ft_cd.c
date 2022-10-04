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

int	change(char *pach)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(pach))
	{
		if (pwd)
		{
			set_env("OLDPWD=", pwd);
			free(pwd);
		}
		pwd = getcwd(NULL, 0);
		if (pwd)
		{
			set_env("PWD=", pwd);
			free(pwd);
		}
		return (1);
	}
	return (0);
}

void	change_directory(char *pach)
{
	struct stat	st;

	if (change(pach))
		return ;
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(pach, 2);
	info.status = 1;
	if (stat(pach, &st) == -1)
		ft_putstr_fd(": No such file or directory", 2);
	else if (!(st.st_mode & S_IXUSR))
		ft_putstr_fd(": Permission denied", 2);
	else
		ft_putstr_fd(": Not a directory", 2);
	ft_putchar_fd('\n', 2);
}

void	directory_home(char *pach, char *pach_2)
{
	if (pach)
	{
		change_directory(ft_strchr(pach, '=') + 1);
		if (!ft_strncmp(pach_2, "~/", 2))
			change_directory(pach_2 + 2);
	}
	else
		ft_putstr_fd("cd:, HOME not set\n", 2);
	info.status = 0;
}

void	directory_olppwd(char *pach)
{
	if (pach)
	{
		change_directory(ft_strchr(pach, '=') + 1);
		ft_putstr_fd(ft_strchr(get_env("PWD"), '=') + 1, 1);
	}
	else
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
}

void	ft_cd(char **args)
{
	char	*pach;

	if (args[0] && args[1])
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		return ; //ERROR
	}
	if (!ft_strncmp(args[0], "-", 2))
		directory_olppwd(get_env("OLDPWD"));
	else if (!ft_strncmp(args[0], "~", 1) || !ft_strncmp(args[0], "--", 3))
		directory_home(get_env("HOME"), args[0]);
	else
	{
		pach = get_env("HOME");
		if (!pach || ft_strncmp(pach, "~/", 2))
			change_directory(args[0]);
		else
			change_directory(ft_strjoin(ft_strchr(pach, '=') + 1, args[0] + 1));
	}
}
