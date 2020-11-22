/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:31 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:29:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "ft_types.h"
# include "ft_utils.h"
# include "ft_vector.h"
# include "ft_memory.h"
# include "mode_libft.h"

void			*matrix_create(size_t rows, size_t cols, size_t type_size);
void			matrix_destroy(t_matrix matrixptr);

void			*matrix_copy(t_matrix matrixptr);
void			matrix_clear(t_matrix matrixptr);

void			matrix_add_row(t_matrix matrixptr);
void			matrix_add_col(t_matrix matrixptr);

size_t			matrix_rows(t_matrix matrixptr);
size_t			matrix_cols(t_matrix matrixptr);

#endif
