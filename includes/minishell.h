/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/15 19:42:18 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
// #include <readline/history.h>

void	init(char **enpv, t_info *info);

//lib funcs
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *value, void *key);
void	ft_pushback(t_list **lst, t_list *elem);
int		ft_isspace(int c);
int		ft_isalpha(int c);

//parsing
void	lexer(t_info *info, char *line);


#endif