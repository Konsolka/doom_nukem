/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:27 by user              #+#    #+#             */
/*   Updated: 2020/11/04 13:44:05 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>

# define WORD_SIZE			64
# define WORD_SIZE_BYTES	8
# define T_INT_WS_MAX		UINT64_MAX

typedef uint_fast64_t		t_int_ws;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef char				*t_string;

typedef void				*t_vector;
typedef int					*t_vector_int;
typedef char				*t_vector_char;
typedef float				*t_vector_float;
typedef double				*t_vector_double;
typedef long				*t_vector_long;
typedef unsigned			*t_vector_unsigned;
typedef size_t				*t_vector_sizet;
typedef char				**t_vector_string;

typedef void				*t_matrix;
typedef int					**t_matrix_int;
typedef char				**t_matrix_char;
typedef float				**t_matrix_float;
typedef double				**t_matrix_double;
typedef long				**t_matrix_long;
typedef unsigned			**t_matrix_unsigned;
typedef size_t				**t_matrix_sizet;

#endif
