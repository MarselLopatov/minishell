/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:46:33 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/17 16:30:03 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_spaces(int *i, t_info *info, char *line)
{
	int	j;

	j = *i;
	while (ft_isspace(line[j]))
		j++;
	if (j > *i)
		ft_pushback(&(info->params), ft_lstnew(" ", "space"));
	*i = j;
}

void	check_words(int *i, t_info *info, char *line)
{
	int	j;

	j = *i;
	while (ft_isalpha(line[j]))
		j++;
	if (j > *i)
		ft_pushback(&(info->params), \
			ft_lstnew(ft_makestr((line + *i), *i, j), "str"));
	*i = j;
}

void	lexer(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		check_words(&i, info, line);
		check_spaces(&i, info, line);
	}
}

// строка из		букв и пробелов