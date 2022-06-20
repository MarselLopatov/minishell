/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:04:29 by coleta            #+#    #+#             */
/*   Updated: 2022/06/20 21:05:34 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **args)
{
	int	i;

	if (args[0])
		; //ERROR
	i = 0;
	while (info.envp[i])
	{
		ft_putstr_fd(info.envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;	
	}
}
