/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:40:35 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/10 15:13:52 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*pull_dollar(char *value)
{
	t_list	*tmp;

	tmp = info.envp_list;
	if (value[0] == '?')
		return (ft_itoa(info.status));
	else
	{
		while (tmp)
		{
			if (!ft_strcmp(value, ((t_envp *)tmp->value)->key))
				return (ft_strdup(((t_envp *)tmp->value)->value));
			tmp = tmp->next;
		}
	}
	return (NULL);
}

int	count_dollar(char *line, int *i)
{
	int		j;
	int		k;
	char	*new;
	char	*help_new;

	j = *i + 1;
	k = 0;
	while (line[j] && ft_isprint(line[j]) && line[j] != ' ' \
		&& line[j] != '$')
		j++;
	help_new = ft_makestr((line + *i + 1), *i, j - 1);
	new = pull_dollar(help_new);
	while (new && new[k])
		k++;
	*i = j;
	free(help_new);
	free(new);
	return (k);
}

int	count_symb(char *str)
{
	int i;
	int counter;

	i = -1;
	counter = 0;
	while (str && str[++i])
	{
		if (str[i] == '$')
			counter += count_dollar(str, &i);
		counter++;
	}
	return (counter);
}

void	copy_dollar(char *line, int *i, int *j, char *copy)
{
	int 	l;
	int		k;
	char	*new;
	char	*new_help;

	k = -1;
	l = *j;
	while (line[*j] && ft_isprint(line[*j]) && line[*j] != ' ' \
		&& line[*j] != '$')
		(*j)++;
	new_help = ft_makestr((line + l), l, *j);
	new = pull_dollar(new_help);
	while (new && new[++k])
	{
		copy[*i] = new[k];
		(*i)++;
	}
	free (new);
	free (new_help);
}

char	*pull_quotes(t_list *token)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (((t_token *)token->value)->key == FIELD)
		return (ft_strdup(((t_token *)token->value)->value));
	else
	{
		copy = malloc (sizeof(char *) * (count_symb(((t_token *)token->value)->value) + 1));
		copy[count_symb(((t_token *)token->value)->value)] = '\0';
		while (((t_token *)token->value)->value && ((t_token *)token->value)->value[j])
		{
			if (((t_token *)token->value)->value[j] == '$')
			{
				j++;
				copy_dollar(((t_token *) token->value)->value, &i, &j, copy);
				if (((t_token *)token->value)->value[j] == '$')
					continue ;
				copy[i] = ((t_token *)token->value)->value[j];
			}
			else
				copy[i] = ((t_token *)token->value)->value[j];
			i++;
			j++;
		}
	}
	return (copy);
}

void	help_fill_argv(t_help *help, t_list *token, int *i)
{
	if (((t_token *)token->value)->key == WORD && (*i) == 0)
		help->cmd = ft_strdup(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == WORD)
		help->argv[(*i) - 1] = ft_strdup(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == DOLLAR)
		help->argv[(*i) - 1] = pull_dollar(((t_token *)token->value)->value);
	else if (((t_token *)token->value)->key == EXP_FIELD || \
		((t_token *)token->value)->key == FIELD)
		help->argv[(*i) - 1] = pull_quotes(token);
	// else if (((t_token *)token->value)->key == REDIR_IN || \
	// 	((t_token *)token->value)->key == REDIR_OUT)
	// 	help->argv[(*i) - 1] = pull_redir();
	(*i)++;
}

void	skip_pipes(int p_i, t_list *token)
{
	static int	pipe_num = 0;

	while (pipe_num < p_i)
	{
		if (((t_token *)token->value)->key == PIPE)
			pipe_num++;
		token = token->next;
	}
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

int	count_cmds(t_list *token, int p_i)
{
	int		pipe_num;
	int		i;

	i = 0;
	pipe_num = 0;
	while (token)
	{
		while (pipe_num < p_i)
		{
			if (((t_token *)token->value)->key == PIPE)
				pipe_num++;
			token = token->next;
		}
		if (((t_token *)token->value)->key == PIPE)
			break ;
		i++;
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
	while (info->help)
	{
		printf("cmd = %s\n", ((t_help *)info->help->value)->cmd);
		for (int i = 0; ((t_help *)info->help->value)->argv[i]; i++)
			printf("argv[%d] = %s\n", i, ((t_help *)info->help->value)->argv[i]);
		info->help = info->help->next;
	}
}
