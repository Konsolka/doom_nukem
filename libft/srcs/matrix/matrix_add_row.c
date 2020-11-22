/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:44:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

#ifdef SAFE_MODE

void			matrix_add_row(t_matrix matrix)
{
	t_matrix_sizet	m;
	void			*new_row;

	if (!matrix)
		ft_error("invalid param \"matrixptr\": NULL", "matrix_add_row", 0);
	m = *(size_t***)matrix;
	new_row = vec_create(vec_size(&m[0]), vec_typesize(&m[0]));
	vec_reserve(&new_row, vec_size(&m[0]));
	vec_pushback(&m, &new_row);
	*(void**)matrix = m;
}

#else

void			matrix_add_row(t_matrix matrix)
{
	t_matrix_sizet	m;
	void			*new_row;

	m = *(size_t***)matrix;
	new_row = vec_create(vec_size(&m[0]), vec_typesize(&m[0]));
	vec_reserve(&new_row, vec_size(&m[0]));
	vec_pushback(&m, &new_row);
	*(void**)matrix = m;
}

#endif
