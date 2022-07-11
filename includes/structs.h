/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:24:45 by cdoria            #+#    #+#             */
/*   Updated: 2022/07/10 17:38:35 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}					t_list;

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
	/* data */
}		t_buildins_ptr;

typedef struct s_info
{
	char				**envp;
	t_list				*envp_list;
	t_list				*token;
	t_list				*help;
	t_buildins_ptr		buildins[7];
	char				*commands[7];
	char				envp_f;
	char				exif_f;
	int					status;
}						t_info;

t_info	info;

#endif