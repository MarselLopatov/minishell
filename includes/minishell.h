/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/17 16:30:49 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
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
char	*ft_makestr(char *str, int i, int j);

//parsing
void	lexer(t_info *info, char *line);

#endif