/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:24:45 by cdoria            #+#    #+#             */
/*   Updated: 2022/06/15 19:27:28 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_list
{
	void			*key;
	void			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_buildins_ptr
{
	/* data */
}		t_buildins_ptr;

typedef struct s_info
{
	char				**envp;
	t_list				*envp_list;
	t_params			*params;
	t_buildins_ptr		buildins[7];
	char				*commands[7];
	char				envp_f;
	char				exif_f;
	int					status;
}						t_info;

typedef	struct s_params
{
	void			*key;
	void			*value;
	struct s_params	*next;
}					t_params;

#endif