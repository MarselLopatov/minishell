/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:19:41 by coleta            #+#    #+#             */
/*   Updated: 2022/06/14 19:25:12 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(char **args)
{
	char	*path;

	if (args[0])
		;//pwd: too many arguments
	path = getcwd(NULL, 0);
	if (!path)
		; // ошибка пути
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}
