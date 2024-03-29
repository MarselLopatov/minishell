/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:51:31 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:43:46 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_pipe(int	*i, t_info *info, char *line)
{
	int	j;

	j = *i;
	if (line[j] != '|')
		return (0);
	ft_pushback(&(info->token), ft_create_token("|", PIPE));
	j++;
	*i = j;
	return (1);
}

int	check_dollar(int *i, t_info *info, char *line)
{
	int	j;

	if (line[*i] != '$')
		return (0);
	j = *i + 1;
	while (line[j] && ft_isprint(line[j]) && line[j] != ' ' \
		&& line[j] != '$' && line[j] != '\"' && line[j] != '\'')
		j++;
	ft_pushback(&(info->token), ft_create_token \
		(ft_makestr((line + *i + 1), *i, j - 1), DOLLAR));
	*i = j;
	return (1);
}

int	check_redirect(int *i, t_info *info, char *line)
{
	if (line[*i] == '>' && line[(*i) + 1] != '>')
		ft_pushback(&(info->token), ft_create_token(ft_strdup(">"), REDIR_IN));
	else if (line[*i] == '<' && line[(*i) + 1] != '<')
		ft_pushback(&(info->token), ft_create_token(ft_strdup("<"), REDIR_OUT));
	else
		return (0);
	(*i)++;
	return (1);
}

int	check_heredoc(int *i, t_info *info, char *line)
{
	if (line[*i] == '>' && line[*i + 1] == '>')
		ft_pushback(&(info->token), \
			ft_create_token(ft_strdup(">>"), REDIR_APPEND));
	else if (line[*i] == '<' && line[*i + 1] == '<')
		ft_pushback(&(info->token), \
			ft_create_token(ft_strdup("<<"), REDIR_INSOURCE));
	else
		return (0);
	(*i) += 2;
	return (1);
}
