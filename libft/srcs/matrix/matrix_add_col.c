/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:28 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:45:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void			matrix_add_col(t_matrix matrix)
{
	t_matrix_sizet	m;
	size_t			rows;
	size_t			iter;
	char			plug[vec_typesize(&(*(size_t***)matrix)[0])];

	m = *(size_t***)matrix;
	rows = vec_size(matrix);
	iter = 0;
	while (iter < rows)
	{
		vec_pushback(&m[iter], plug);
		++iter;
	}
}
