/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:39:48 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 14:39:49 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	norm_l(int *i, int *z, long *n)
{
	*i = 0;
	*z = 1;
	*n = 0;
}

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	int		z;

	norm_l(&i, &z, &n);
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			z = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		if (n * z > 2147483647)
			return (-1);
		else
			if (n * z < -2147483648)
				return (0);
		n = n * 10 + (str[i] - 48);
		i ++;
	}
	return (n * z);
}
