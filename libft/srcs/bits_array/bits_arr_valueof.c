/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_valueof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:25:45 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"

#ifdef SAFE_MODE

bool			barr_valueof(t_barr *arr, size_t index)
{
	size_t		word;
	uint16_t	bit;
	t_int_ws	mask;

	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_valueof", 0);
	if (index >= arr->size_in_bits)
		ft_error("invalid param \"index\": out of range", "barr_valueof", 0);
	word = index / WORD_SIZE;
	bit = index & (WORD_SIZE - 1);
	mask = (t_int_ws)1 << (WORD_SIZE - 1 - bit);
	return ((arr->data[word] & mask) ? true : false);
}

#else

bool			barr_valueof(t_barr *arr, size_t index)
{
	size_t		word;
	uint16_t	bit;
	t_int_ws	mask;

	word = index / WORD_SIZE;
	bit = index & (WORD_SIZE - 1);
	mask = (t_int_ws)1 << (WORD_SIZE - 1 - bit);
	return ((arr->data[word] & mask) ? true : false);
}

#endif
