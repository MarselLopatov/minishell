/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:07:26 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/12 22:33:44 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back_c(t_comand **lst, t_comand *new)
{
	t_comand	*r;

	if (*lst == (void *)0)
		*lst = new;
	else
	{
		r = *lst;
		while (r != (void *)0)
		{
			if (r->next == (void *)0)
			{
				r->next = new;
				break ;
			}
			r = r->next;
		}
	}
}

char	**ft_mstrdup(char **s)
{
	char	**new;
	int		i;

	i = 0;
	// if (s[0] == NULL)//init argv
	// 	return (NULL);
	while (s[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (s[i])
	{
		new[i] = ft_strdup(s[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

t_comand	*ft_lstnew_c(t_help *content)
{
	t_comand	*new;

	new = (t_comand *)malloc(sizeof(t_comand));
	if (!new)
		return (NULL);
	new->cmd = content->cmd;
	new->args = content->argv;
	new->next = NULL;
	return (new);
}

void	init_comand(t_info *info)
{
	t_comand	*comand;
	t_list		*temp;
	t_help		*t;

	comand = NULL;
	temp = info->help;
	while (temp != NULL)
	{
		t = ((t_help *)temp->value);
		ft_lstadd_back_c(&comand, ft_lstnew_c(t));
		temp = temp->next;
	}
	info->comand = comand;
}

void	parser(t_info *info)
{
	preparser(info);
	split_tokens(info);
	init_comand(info);
	// executor(info);
}
