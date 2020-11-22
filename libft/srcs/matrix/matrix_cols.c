/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:34:29 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:41:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

#ifdef SAFE_MODE

size_t			matrix_cols(t_matrix matrix)
{
	if (!matrix)
		ft_error("invalid param \"matrixptr\": NULL", "matrix_cols", 0);
	return (vec_size(*(void**)matrix));
}

#else

inline size_t	matrix_cols(t_matrix matrix)
{
	return (vec_size(*(void**)matrixptr));
}

#endif
