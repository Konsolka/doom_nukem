/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_warning.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:26 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:44:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_WARNING_H
# define PRIVATE_WARNING_H

typedef struct			s_warning
{
	char				*message;
	struct s_warning	*next;
}						t_warning;

typedef struct			s_warning_list
{
	t_warning			*errors;
	t_warning			*warnings;
	t_warning			*errors_end;
	t_warning			*warnings_end;
}						t_warning_list;

t_warning_list			**get_warning_list(void);

#endif
