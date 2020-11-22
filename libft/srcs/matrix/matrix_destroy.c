/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:46:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

#ifdef SAFE_MODE

void			matrix_destroy(t_matrix matrix)
{
	size_t			iter;
	size_t			rows;
	t_matrix_sizet	m;

	if (!matrix)
		ft_error("invalid param \"matrixptr\": NULL", "matrix_destroy", 0);
	m = *(t_matrix_sizet*)matrix;
	rows = vec_size(&m);
	iter = 0;
	while (iter < rows)
	{
		vec_destroy(m + iter);
		++iter;
	}
	vec_destroy(&m);
}

#else

void			matrix_destroy(t_matrix matrix)
{
	size_t			iter;
	size_t			rows;
	t_matrix_sizet	matrix;

	matrix = *(t_matrix_sizet*)matrixptr;
	rows = vec_size(&matrix);
	iter = 0;
	while (iter < rows)
	{
		vec_destroy(matrix + iter);
		++iter;
	}
	vec_destroy(&matrix);
}

#endif
