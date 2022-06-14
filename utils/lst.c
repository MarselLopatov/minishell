/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:04:17 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/14 19:32:21 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstnew(void *value, void *key)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->key = key;
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
