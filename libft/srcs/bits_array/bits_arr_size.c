/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:50 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/07 14:35:10 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"

#ifdef SAFE_MODE

size_t				barr_size(t_barr *arr)
{
	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_size", 0);
	return (arr->size_in_bits);
}

#else

inline size_t		barr_size(t_barr *arr)
{
	return (arr->size_in_bits);
}

#endif
