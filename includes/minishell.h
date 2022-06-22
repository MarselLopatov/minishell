/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/22 18:42:05 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "includes.h"

void	init(char **enpv, t_info *info);

//lib funcs
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *value);
void	ft_pushback(t_list **lst, t_list *elem);
int		ft_isspace(int c);
int		ft_isalpha(int c);
char	*ft_makestr(char *str, int i, int j);
int		ft_isprint(int c);

//lexer
void	lexer(t_info *info, char *line);
int		check_pipe(int *i, t_info *info, char *line);
int		check_dollar(int *i, t_info *info, char *line);
int		check_redirect(int *i, t_info *info, char *line);
int		check_heredoc(int *i, t_info *info, char *line);
t_list	*ft_create_token(char *value, int key);
t_list	*ft_create_envp(char *str1, char *str2);
t_list	*ft_create_help(t_list *token, int p_i);

//parser
void	parser(t_info *info);
void	split_tokens(t_info *info);
int		count_pipes(t_list	*params);
int		count_cmds(t_list *params, int p_i);
void	fill_argv(t_help *help, t_list *tmp, int p_i);

#endif