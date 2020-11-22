/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:23 by user              #+#    #+#             */
/*   Updated: 2020/04/26 21:50:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>
# include "ft_types.h"
# include "ft_utils.h"
# include "ft_memory.h"
# include "mode_libft.h"

void		*vec_create(int elems, int type_size);
void		vec_destroy(t_vector vecptr);

void		vec_pushback(t_vector vecptr, void *elem);
void		vec_popback(t_vector vector);

void		*vec_copy(t_vector vecptr, bool save_capacity);
void		vec_shrink_to_fit(t_vector vecptr);
void		vec_reserve(t_vector vecptr, int size);

int			vec_size(t_vector vecptr);
int			vec_capacity(t_vector vecptr);
int			vec_typesize(t_vector vecptr);

#endif
