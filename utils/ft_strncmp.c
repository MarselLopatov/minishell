/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:38:20 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:38:22 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1 && str2)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
		{
			return ((unsigned char)str1[i] - str2[i]);
			break ;
		}
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - str2[i]);
	}
	return (0);
}
