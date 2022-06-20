/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:45:06 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 20:32:12 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_create_help(char *cmd, char **argv)
{
	t_help	*help;

	help = malloc(sizeof(t_help));
	if (!help)
		return (NULL);
	help->cmd = cmd;
	help->argv = argv;
	ft_lstnew(help);
}
