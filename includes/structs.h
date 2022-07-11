/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:24:45 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/20 19:39:01 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}					t_list;


// typedef struct s_exe

typedef struct s_envp
{
	char	*key;
	char	*value;
}			t_envp;

typedef struct s_token
{
	int				key;
	char			*value;
}					t_token;

typedef struct s_help
{
	char	*cmd;
	char	**argv;
	int		fd;
	char	*redir_in;
	char	*redir_out;
	char	*heredok;
	int		pipe;
}		t_help;

typedef struct s_buildins_ptr
{
	int		pid;
}			t_exe;

typedef struct s_comand
{
	char			*cmd;
	char			**args;
	int				fd_in_out[3];
	int				fd_close[2];
	
	int				flag_pipe;
	char			*redirect_in;
	char			*redirect_out;
	struct s_comand *next;
}		t_comand;

typedef struct s_info
{
	char				**envp;
	t_list				*envp_list;
	// t_list				*params;
	t_comand			*comand;

	t_list				*token;
	t_list				*help;
	// t_buildins_ptr		buildins[7];
	char				*commands[7];
	char				envp_f;
	char				exif_f;
	int					status;
}						t_info;

t_info	info;

#endif