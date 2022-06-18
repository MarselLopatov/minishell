/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:53:24 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/17 16:28:36 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_makestr(char *str, int i, int j)
{
	int		k;
	char	*new;

	new = malloc (sizeof(char) * (j - i));
	if (!new)
		return (NULL);
	new[j - i - 1] = '\0';
	k = 0;
	while (i < j)
	{
		new[k] = str[k];
		k++;
		i++;
	}
	return (new);
}
