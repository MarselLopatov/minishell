/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:18:49 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 17:53:08 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	help_fill_argv(t_help *help, t_list *token, int *i)
{
	if ((((t_token *)token->value)->key == WORD || \
			((t_token *)token->value)->key == EXP_FIELD \
				|| ((((t_token *)token->value)->key == FIELD))) && (*i) == 0)
		help->cmd = ft_strdup(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == WORD)
		help->argv[(*i) - 1] = ft_strdup(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == DOLLAR)
		help->argv[(*i) - 1] = pull_dollar(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == EXP_FIELD || \
		((t_token *)token->value)->key == FIELD)
		help->argv[(*i) - 1] = pull_quotes(token);
	else if (((t_token *)token->value)->key == REDIR_IN || \
		((t_token *)token->value)->key == REDIR_OUT || \
		((t_token *)token->value)->key == REDIR_APPEND)
		pull_redir(help, token);
	(*i)++;
}

void	fill_argv(t_help *help, t_list *tmp, int p_i)
{
	int		i;
	int		pipe_num;
	t_list	*token;

	i = 0;
	pipe_num = 0;
	token = tmp;
	while (token && ((t_token *)token->value)->key != PIPE)
	{
		while (pipe_num < p_i)
		{
			if (((t_token *)token->value)->key == PIPE)
				pipe_num++;
			token = token->next;
		}
		help_fill_argv(help, token, &i);
		token = token->next;
	}
}

void	free_parser(t_info *info)
{
	while (info->token)
	{
		free(((t_token *)info->token->value)->value);
		info->token = info->token->next;
	}
	free(info->token);
	info->token = NULL;
	while (info->help)
	{
		free(((t_help *)info->help->value)->argv);
		free(((t_help *)info->help->value)->cmd);
		free(((t_help *)info->help->value)->heredok);
		free(((t_help *)info->help->value)->redir_in);
		free(((t_help *)info->help->value)->redir_out);
		info->help = info->help->next;
	}
	free(info->help);
	info->help = NULL;
}
