/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:39:44 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/22 17:07:40 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_pipes(t_list	*token)
{
	int	i;

	i = 0;
	while (token)
	{
		if (((t_token *)token->value)->key == PIPE)
			i++;
		token = token->next;
	}
	return (i);
}
