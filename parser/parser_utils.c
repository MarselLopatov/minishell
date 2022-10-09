/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:39:44 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 17:20:22 by cdoria           ###   ########.fr       */
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

char	*pull_dollar(char *value)
{
	t_list	*tmp;

	tmp = g_info.envp_list;
	if (value[0] == '?')
		return (ft_itoa(g_info.status));
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
	int	i;
	int	counter;

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
