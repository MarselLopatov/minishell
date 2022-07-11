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
t_list	*ft_lstnew(void *value);
void	ft_pushback(t_list **lst, t_list *elem);
int		ft_isspace(int c);
int		ft_isalpha(int c);
char	*ft_makestr(char *str, int i, int j);
int		ft_isprint(int c);
char	*ft_strchr(const char *s, int c);
void	*ft_realloc(void *old, size_t new_size);

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

//executor
void	chech_comand(char *cmd);
char	**get_paths(char **envp);
int		count_comand(t_comand *comand);
void	free_comand(t_comand *comand);
int		more_cmd(int number_cmd);



//built
int		ft_builtins(t_comand *comand);
void	ft_unset(char **args);
void	ft_pwd(char **args);
void	ft_env(char **args);
void	ft_echo(char **args);
void	ft_cd(char **args);
void	ft_export(char **args);
void	ft_exit(char **args);

//built utils
char	*get_name(char *str);
void	alph_sorting(char **str, int n);
int		index_equals(char *str);
void	add_export(char *new);
void	set_env(char *name, char *pach);
char	*get_env(char *name);

#endif