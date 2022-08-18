/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:07:26 by cdoria            #+#    #+#             */
/*   Updated: 2022/08/17 15:24:10 by cdoria           ###   ########.fr       */
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
	new = malloc(sizeof(char *) * (i + 2));
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
	int			i;

	new = (t_comand *)malloc(sizeof(t_comand));
	if (!new)
		return (NULL);
	i = 0;
	new->cmd = ft_strdup(content->cmd);
	new->args = ft_mstrdup(content->argv);
	//реализовать нормальный выбор
	new->fd_in_out[0] = 0;
	if (content->fd)
		new->fd_in_out[1] = content->fd;
	else
		new->fd_in_out[1] = 1;
	new->fd_in_out[2] = 2;
	new->fd_close[0] = -1;
	new->fd_close[1] = -1;
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
	cmds_fds(comand, ((t_help *)info->help->value)->pipe + 1);
	info->comand = comand;
}

void	free_parser(t_info *info)
{
	info->token = NULL;
	info->help = NULL;
}

void	parser(t_info *info)
{
	preparser(info);
	split_tokens(info);
	init_comand(info);
	free_parser(info);
}
