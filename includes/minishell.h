/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:39:36 by cdoria            #+#    #+#             */
/*   Updated: 2022/10/09 17:54:09 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "includes.h"

void	init(char **enpv, t_info *info);

//lib funcs
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *value);
void	ft_pushback(t_list **lst, t_list *elem);
int		ft_isspace(int c);
int		ft_isalpha(int c);
char	*ft_makestr(char *str, int i, int j);
int		ft_isprint(int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

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
void	preparser(t_info *info);
char	*pull_dollar(char *value);
char	*pull_quotes(t_list *token);
void	pull_redir(t_help *help, t_list *token);
int		count_symb(char *str);
void	free_parser(t_info *info);

//executor
int		executor(t_info *data);
void	chech_comand(t_comand *c);
char	**get_paths(char **envp);
int		count_comand(t_comand *comand);
void	free_comand(t_comand *comand);
int		more_cmd(int number_cmd);
void	cmds_fds(t_comand *cmds, int size);

//built
int		ft_builtins(t_comand *comand);
void	ft_unset(char **args);
void	ft_pwd(char **args);
void	ft_env(char **args);
void	ft_echo(char **args);
void	ft_cd(char **args);
void	ft_export(char **args);
void	ft_exit(char **args);
void	add_export(char *new);
char	**add_cmd(t_comand *data);

//built utils
char	*get_name(char *str);
void	alph_sorting(char **str, int n);
int		index_equals(char *str);
// void	add_export(char *new);
void	set_env(char *name, char *pach);
char	*get_env(char *name);

//signal
int		accept_signals(void);

#endif