/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:51:31 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/17 19:11:46 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_pipe(int	*i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '|')
		return ;
	ft_pushback(&(info->params), ft_lstnew("|", "pipe"));
	j++;
	*i = j;
}

void	check_dollar(int *i, t_info *info, char *line)
{
	int	j;

	if (line[*i] != '$')
		return ;
	j = *i + 1;
	while (ft_isalpha(line[j]))
		j++;
	if (j == *i)
	{
		printf("ERROR\n");
		// exit(1);
	}
	ft_pushback(&(info->params), ft_lstnew \
		(ft_makestr((line + *i + 1), *i, j), "dollar"));
	*i = j;
}
