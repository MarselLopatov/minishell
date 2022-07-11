/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:45:06 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/22 20:59:29 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_create_help(t_list *token, int p_i)
{
	t_help	*help;

	help = malloc(sizeof(t_help));
	if (!help)
		return (NULL);
	help->argv = (char **) malloc (sizeof(char *) * count_cmds(token, p_i));
	if (!help->argv)
		return (NULL);
	fill_argv(help, token, p_i);
	return (ft_lstnew(help));
}
