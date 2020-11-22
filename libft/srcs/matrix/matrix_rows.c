/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:30 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:36:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

#ifdef SAFE_MODE

size_t			matrix_rows(t_matrix matrix)
{
	if (!matrix)
		ft_error("invalid param \"matrixptr\": NULL", "matrix_rows", 0);
	return (vec_size(matrix));
}

#else

inline size_t	matrix_rows(t_matrix matrix)
{
	return (vec_size(matrix));
}

#endif
