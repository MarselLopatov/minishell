/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:40:35 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 21:22:41 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	help_fill_argv(t_help help, t_list *params, int i)
{
	if (((t_token *)params)->key == WORD && i == 0)
		help.cmd = params->value;
	else if (((t_token *)params)->key == WORD)
		help.argv = params->value;
	else if (((t_token *)params)->key == DOLLAR)
		help.argv = pull_dollar();
	else if (((t_token *)params)->key == REDIR_IN || \
		((t_token *)params)->key == REDIR_OUT)
		help.argv = pull_redir();
	else if (((t_token *)params)->key == EXP_FIELD || \
		((t_token *)params)->key == FIELD)
		help.argv = pull_quotes();
}

void	fill_argv(t_help help, t_list *params, int p_i)
{
	int	i;
	int	pipe_num;

	i = 0;
	pipe_num = 0;
	while (params)
	{
		if (pipe_num < p_i)
		{
			if (((t_token *)params)->key == PIPE)
				pipe_num++;
			params = params->next;
			continue ;
		}
		help_fill_argv(help, params, i);
		params = params->next;
		i++;
	}
}

int	count_cmds(t_list *token)
{
	t_list	*tmp;

	tmp = token;
	while (token && ((t_token *)token->value)->key != PIPE)
	{
		
	}
	int	i;
	int	pipe_num;

	i = 0;
	pipe_num = 0;
	while (token)
	{
		if (pipe_num < p_i)
		{
			if (((t_token *)params)->key == PIPE)
				pipe_num++;
			params = params->next;
			continue ;
		}
		if (((t_token *)params)->key == WORD)
			i++;
		params = params->next;
	}
	return (i);
}

void	split_tokens(t_info *info)
{
	t_list	*tmp;
	int		i;
	int		c_pipes;

	i = 0;
	c_pipes = count_pipes(info->token);
	tmp = info->token;
	while (i <= c_pipes)
	{
		// чето надо сделать
		i++;
	}
}

// echo why not | kek