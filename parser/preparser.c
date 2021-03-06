/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:41:53 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/10 17:59:06 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	del_sep(t_info *info)
{
	t_list	*tmp;
	t_list	*help;

	tmp = info->token;
	help = tmp;
	while(tmp)
	{
		if (((t_token *)tmp->value)->key == SEP)
		{
			help->next = help->next->next;
			free(tmp);
			tmp = help;
		}
		help = tmp;
		tmp = tmp->next;
	}
}

void	check_double_pipes(t_info *info)
{
	t_list	*tmp;

	tmp = info->token;
	while(tmp)
	{
		if (((t_token *)tmp->value)->key == PIPE && \
			((t_token *)tmp->next->value)->key == PIPE)
			exit(100);
		tmp = tmp->next;
	}
}

void	preparser(t_info *info)
{
	del_sep(info);
	check_double_pipes(info);
	// while (info->token)
	// {
	// 	printf("key = %d, value = %s\n", ((t_token *)info->token->value)->key, ((t_token *)info->token->value)->value);
	// 	info->token = info->token->next;
	// }
}
