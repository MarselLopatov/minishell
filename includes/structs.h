/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleta <coleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:24:45 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/14 19:06:56 by coleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_list
{
	void					*key;
	void					*value;
	typedef	struct s_list	*next;
}							t_list;

typedef struct s_buildins_ptr
{
	/* data */
}		t_buildins_ptr;

typedef struct s_info
{
	char				**envp;
	t_list				envp_list;
	t_buildins_ptr		buildins[7];
	char				commands[7];
	char				envp_f;
	char				exif_f;
	int					status;
}						t_info;

#endif