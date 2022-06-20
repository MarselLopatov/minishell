/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:10 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/19 19:15:14 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	char	*line;

	(void)argc;
	(void)argv;
	init(envp, &info);
	while (1)
	{
		line = readline("minishell: ");
		add_history(line);
		lexer(&info, line);
		break;
	}
}
