/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:24:45 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/19 18:04:39 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	void			*key;
	void			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_exe
{
	int		pid;
}			t_exe;

typedef struct s_comand
{
	char			*cmd;
	char			**args;
	int				flag_pipe;
	char			*redirect_in;
	char			*redirect_out;
	struct s_comand *next;
}		t_comand;

typedef struct s_info
{
	char				**envp;
	t_list				*envp_list;
	t_list				*params;
	t_comand			*comand;
	char				*commands[7];
	char				envp_f;
	char				exif_f;
	int					status;
}						t_info;

#endif