/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:19:41 by coleta            #+#    #+#             */
/*   Updated: 2022/07/12 23:33:44 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(char **args)
{
	char	*path;

	if (args[0] != NULL)
		return ;//pwd: too many arguments
	path = getcwd(NULL, 0);
	if (!path)
		return ; // ошибка пути
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}
