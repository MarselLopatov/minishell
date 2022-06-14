/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:16:28 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/14 20:31:41 by coleta           ###   ########.fr       */
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
		info->envp[i] = envp[i];
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
		ft_pushback(&(info->envp_list), ft_lstnew(strs[0], strs[1]));
		i++;
	}
}

void	init(char **envp, t_info *info)
{
	info->exif_f = 0;
	info->envp_f = 1;
	info->status = 1;
	copy_envp(info, envp);
	envp_list(info);
}
