/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:40:35 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/27 20:42:27 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_cut_field(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			
			continue ;
		}
		count++;
	}
}

char	*pull_dollar(char *value)
{
	t_list	*tmp;

	tmp = info.envp_list;
	if (value[0] == '$')
		return(ft_itoa(get_pid()));
	else if (value[0] == '?')
		return (ft_itoa(info.status));
	else
	{
		while (tmp)
		{
			if (!ft_strcmp((value + 1), ((t_envp *)tmp->value)->value))
				return (ft_strdup(((t_envp *)tmp->value)->value));
			tmp = tmp->next;
		}
	}
	return (NULL);
}

void	help_fill_argv(t_help *help, t_list *token, int i)
{
	if (((t_token *)token->value)->key == WORD && i == 0)
		help->cmd = token->value;
	else if (((t_token *)token->value)->key == WORD)
		help->argv[i] = token->value;
	else if (((t_token *)token->value)->key == DOLLAR)
		help->argv[i] = pull_dollar(((t_token *)token->value)->value);
	// else if (((t_token *)token->value)->key == REDIR_IN || \
	// 	((t_token *)token->value)->key == REDIR_OUT)
	// 	help->argv[i] = pull_redir();
	// else if (((t_token *)token->value)->key == EXP_FIELD || \
	// 	((t_token *)token->value)->key == FIELD)
	// 	help->argv[i] = pull_quotes();
}

void	fill_argv(t_help *help, t_list *tmp, int p_i)
{
	int		i;
	int		pipe_num;
	t_list	*token;

	i = 0;
	pipe_num = 0;
	token = tmp;
	while (token)
	{
		if (pipe_num < p_i)
		{
			if (((t_token *)token->value)->key == PIPE)
				pipe_num++;
			token = token->next;
			continue ;
		}
		help_fill_argv(help, token, i);
		token = token->next;
		i++;
	}
}

int	count_cmds(t_list *token, int p_i)
{
	t_list	*tmp;
	int		pipe_num;
	int		i;

	tmp = token;
	i = 0;
	pipe_num = 0;
	while (token)
	{
		if (pipe_num < p_i)
		{
			if (((t_token *)token->value)->key == PIPE)
				pipe_num++;
			token = token->next;
			continue ;
		}
		if (((t_token *)token->value)->key == WORD)
			i++;
		if (((t_token *)token->value)->key == PIPE)
			break ;
		token = token->next;
	}
	return (i);
}

void	split_tokens(t_info *info)
{
	t_list	*tmp;
	int		i;
	int		c_pipes;

	i = 0;
	tmp = info->token;
	c_pipes = count_pipes(info->token);
	while (i <= c_pipes)
	{
		ft_pushback(&(info->help), ft_create_help(info->token, i));
		i++;
	}
}

// echo why not | kek