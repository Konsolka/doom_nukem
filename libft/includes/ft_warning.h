/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warning.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:15 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:23:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WARNING_H
# define FT_WARNING_H

# include <stdarg.h>
# include "ft_types.h"
# include "ft_vector.h"
# include "ft_buf.h"

# define WARNING				(0)
# define ERROR					(1)

typedef bool			t_warning_type;

void			warning_create(void);
void			warning_add(t_warning_type type, int message_parts, ...);
void			warning_print(void);
void			warning_destroy(void);

#endif
