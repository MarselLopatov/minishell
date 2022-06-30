#include "../includes/minishell.h"

char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

void	chech_comand(char *cmd)
{
	char	**paths;
	char	*path;
	char	*path_cmd;
	int		i;

	i = 0;
	paths = get_paths(info.envp);
	path_cmd = ft_strjoin("/", cmd);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], path_cmd);
		if (!access(path, X_OK))
		{
			// free(cmd);
			cmd = path;
			break ;
		}
		free(path);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(path_cmd);
}
