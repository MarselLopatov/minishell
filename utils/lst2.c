/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:45:06 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/10 20:02:58 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_create_help(t_list *token, int p_i)
{
	t_help	*help;
	int		counter;

	counter = count_cmds(token, p_i);
	printf("%d\n", counter);
	help = malloc(sizeof(t_help));
	if (!help)
		return (NULL);
	help->argv = (char **) malloc (sizeof(char *) * (counter));
	if (!help->argv)
		return (NULL);
	help->argv[counter - 1] = NULL;
	help->fd = 0;
	help->pipe = 0;
	help->redir_in = NULL;
	help->redir_out = NULL;
	help->heredok = NULL;
	fill_argv(help, token, p_i);
	return (ft_lstnew(help));
}
