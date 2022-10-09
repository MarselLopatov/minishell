/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:10 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 17:11:25 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	init(envp, &g_info);
	while (1)
	{
		if (accept_signals())
			exit (-1);
		line = readline("minishell: ");
		if (line == NULL)
			exit(0);
		if (*line == '\0')
			continue ;
		add_history(line);
		lexer(&g_info, line);
		executor(&g_info);
	}
}
