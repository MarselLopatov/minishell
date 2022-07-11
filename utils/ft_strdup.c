/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:26:18 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/27 18:26:32 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	str[ft_strlen(s)] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
