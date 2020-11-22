/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:39:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

#ifdef SAFE_MODE

static void		check_args(size_t rows, size_t cols, size_t type_size)
{
	if (!rows)
		ft_error("invalid param \"rows\": cannot be 0", "matrix_create", 0);
	if (!cols)
		ft_error("invalid param \"cols\": cannot be 0", "matrix_create", 0);
	if (!type_size)
		ft_error("invalid param \"type_size\": cannot be 0",
				"matrix_create", 0);
}

void			*matrix_create(size_t rows, size_t cols, size_t type_size)
{
	t_matrix_sizet	matrix;
	size_t			iter;

	check_args(rows, cols, type_size);
	matrix = vec_create(rows, sizeof(t_matrix));
	vec_reserve(&matrix, rows);
	iter = 0;
	while (iter < rows)
	{
		matrix[iter] = vec_create(cols, type_size);
		vec_reserve(&matrix[iter], cols);
		++iter;
	}
	return (matrix);
}

#else

void			*matrix_create(size_t rows, size_t cols, size_t type_size)
{
	t_matrix_sizet	matrix;
	size_t			iter;

	matrix = vec_create(rows, sizeof(t_matrix));
	vec_reserve(&matrix, rows);
	iter = 0;
	while (iter < rows)
	{
		matrix[iter] = vec_create(cols, type_size);
		vec_reserve(&matrix[iter], cols);
		++iter;
	}
	return (matrix);
}

#endif
