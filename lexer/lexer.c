/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:46:33 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/17 19:25:00 by cdoria           ###   ########.fr       */
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

void	check_double_quotation(int	*i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '\"')
		return ;
	j++;
	while (line[j] != '\"' && line[j])
		j++;
	if (!line[j])
	{
		printf("ERROR\n");
		exit(1);
	}
	if (j > *i)
		ft_pushback(&(info->params), ft_lstnew \
			(ft_makestr((line + *i + 1), *i, j - 1), "double quotation"));
	*i = j + 1;
}

void	check_quotation(int	*i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '\'')
		return ;
	j++;
	while (line[j] != '\'' && line[j])
		j++;
	if (!line[j])
	{
		printf("ERROR\n");
		exit(1);
	}
	if (j > *i)
		ft_pushback(&(info->params), ft_lstnew \
			(ft_makestr((line + *i + 1), *i, j - 1), "quotation"));
	*i = j + 1;
}

void	lexer(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		check_words(&i, info, line);
		check_spaces(&i, info, line);
		check_double_quotation(&i, info, line);
		check_quotation(&i, info, line);
		check_pipe(&i, info, line);
		// check <   >
		
		// check << >>
		
		check_dollar(&i, info, line);
	}
	while (info->params)
	{
		printf("key = %s, value = %s\n", info->params->key, info->params->value);
		info->params = info->params->next;
	}
}

// строка из		букв и пробелов