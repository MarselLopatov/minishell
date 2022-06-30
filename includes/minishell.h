/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 19:47:10 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include "include.h"

# define READ_FD 0
# define WRITE_FD 1
# define ERR_FD 2

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
char	*ft_strchr(const char *s, int c);
void	*ft_realloc(void *old, size_t new_size);

//parsing
void	lexer(t_info *info, char *line);
void	check_pipe(int *i, t_info *info, char *line);
void	check_dollar(int *i, t_info *info, char *line);

//built
int		ft_builtins(t_comand *comand);
void	ft_unset(char **args);
void	ft_pwd(char **args);
void	ft_env(char **args);
void	ft_echo(char **args);
void	ft_cd(char **args);
void	ft_export(char **args);

//built utils
char	*get_name(char *str);
void	alph_sorting(char **str, int n);
int		index_equals(char *str);
void	add_export(char *new);
void	set_env(char *name, char *pach);
char	*get_env(char *name);

#endif