/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:04:17 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 20:31:59 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_create_token(char *value, int key)
{
	t_token	*token;

	token = malloc (sizeof(t_token));
	if (!token)
		return (NULL);
	token->key = key;
	token->value = value;
	return (ft_lstnew(token));
}

t_list	*ft_create_envp(char *key, char *value)
{
	t_envp	*env;

	env = malloc (sizeof(t_envp));
	if (!env)
		return (NULL);
	env->key = key;
	env->value = value;
	return (ft_lstnew(env));
}

t_list	*ft_lstnew(void *value)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_pushback(t_list **lst, t_list *elem)
{
	t_list	*tmp;

	if (!lst || !elem)
		return ;
	if (!*lst)
	{
		*lst = elem;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = elem;
}
