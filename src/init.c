/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:16:28 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 18:44:05 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_envp(t_info *info, char **envp)
{
	int		i;
	int		count;

	count = 0;
	while (envp[count])
		count++;
	info->envp = malloc (sizeof(char *) * (count + 1));
	if (!info->envp)
		return ;
	i = 0;
	while (i < count)
	{
		info->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	info->envp[i] = NULL;
}

void	envp_list(t_info *info)
{
	char	**strs;
	int		i;

	i = 0;
	while (info->envp[i])
	{
		strs = ft_split(info->envp[i], '=');
		ft_pushback(&(info->envp_list), ft_create_envp(strs[0], strs[1]));
		i++;
	}
}

void	make_commands(t_info *info)
{
	info->commands[0] = "echo";
	info->commands[1] = "cd";
	info->commands[2] = "pwd";
	info->commands[3] = "export";
	info->commands[4] = "unset";
	info->commands[5] = "env";
	info->commands[6] = "exit";
}

void	init(char **envp, t_info *info)
{
	signal(SIGINT, sigint_handler);// ^C
	signal(SIGQUIT, SIG_IGN);//"^\"
	info->exif_f = 0;
	info->envp_f = 1;
	info->status = 0;
	copy_envp(info, envp);
	envp_list(info);
	make_commands(info);
}
