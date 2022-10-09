/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:47:01 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:50:31 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

void	free_path(char **paths, char *path_cmd)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(path_cmd);
}

void	chech_comand(t_comand *c)
{
	char	**paths;
	char	*path;
	char	*path_cmd;
	int		i;

	i = 0;
	paths = get_paths(g_info.envp);
	path_cmd = ft_strjoin("/", c->cmd);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], path_cmd);
		if (!access(path, X_OK))
		{
			if (c->cmd)
				free(c->cmd);
			c->cmd = path;
			break ;
		}
		free(path);
		i++;
	}
	free_path(paths, path_cmd);
}
