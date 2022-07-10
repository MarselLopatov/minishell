/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:46:33 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/10 15:08:27 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_spaces(int *i, t_info *info, char *line)
{
	int		j;

	j = *i;
	while (line[j] && ft_isspace(line[j]))
		j++;
	if (j > *i)
		ft_pushback(&(info->token), ft_create_token(ft_strdup(" "), SEP));
	else
		return (0);
	*i = j;
	return (1);
}

int	check_words(int *i, t_info *info, char *line)
{
	int	j;

	j = *i;
	while (line[j] && ft_isprint(line[j]) && !ft_isspace(line[j]) && \
		line[j] != '|' && line[j] != '$' && line[j] != '>' && \
		line[j] != '<' && line[j] != '|' && line[j] != '\'' && \
		line[j] != '\"' && line[j] != '\\' && line[j] != ';')
		j++;
	if (j > *i)
		ft_pushback(&(info->token), \
			ft_create_token(ft_makestr((line + *i), *i, j), WORD));
	else
		return (0);
	*i = j;
	return (1);
}

int	check_double_quotation(int *i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '\"')
		return (0);
	j++;
	while (line[j] && line[j] != '\"')
		j++;
	if (!line[j])
	{
		printf("ERROR\n");
		exit(1);
	}
	if (j > *i)
		ft_pushback(&(info->token), ft_create_token \
			(ft_makestr((line + *i + 1), *i, j - 1), EXP_FIELD));
	*i = j + 1;
	return (1);
}

int	check_quotation(int	*i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '\'')
		return (0);
	j++;
	while (line[j] && line[j] != '\'')
		j++;
	if (!line[j])
	{
		printf("ERROR\n");
		exit(1);
	}
	if (j > *i)
		ft_pushback(&(info->token), ft_create_token \
			(ft_makestr((line + *i + 1), *i, j - 1), FIELD));
	*i = j + 1;
	return (1);
}

void	lexer(t_info *info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\\' || line[i] == ';')
		{
			printf("ERROR\n");
			return ;
		}
		check_spaces(&i, info, line);
		check_pipe(&i, info, line);
		check_quotation(&i, info, line);
		check_heredoc(&i, info, line);
		check_words(&i, info, line);
		check_double_quotation(&i, info, line);
		check_dollar(&i, info, line);
		check_redirect(&i, info, line);
	}
	// while (info->token)
	// {
	// 	printf("key = %d, value = %s\n", ((t_token *)info->token->value)->key, ((t_token *)info->token->value)->value);
	// 	info->token = info->token->next;
	// }
	parser(info);
}

// препарсер будет проверять на ошибки и валидность (например  ; или | в началае)
// мой список должен создавать элемет на структуру