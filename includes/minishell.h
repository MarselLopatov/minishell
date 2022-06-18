/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/18 19:04:32 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "includes.h"
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
int		ft_isprint(int c);

//parsing
void	lexer(t_info *info, char *line);
int		check_pipe(int *i, t_info *info, char *line);
int		check_dollar(int *i, t_info *info, char *line);
int		check_redirect(int *i, t_info *info, char *line);
int		check_heredoc(int *i, t_info *info, char *line);
void	parser(t_info *info);

#endif