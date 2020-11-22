/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_set_as_true.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:44:40 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"

#ifdef SAFE_MODE

void		barr_set_as_true(t_barr *arr, size_t bit_index)
{
	size_t		word;
	uint16_t	bit;
	t_int_ws	mask;

	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_set_as_true", 0);
	if (bit_index >= arr->size_in_bits)
		ft_error("invalid param \"bit_index\": out of range",
				"barr_set_as_true", 0);
	word = bit_index / WORD_SIZE;
	bit = bit_index & (WORD_SIZE - 1);
	mask = ((t_int_ws)1 << (WORD_SIZE - 1 - bit));
	arr->data[word] |= mask;
}

#else

void		barr_set_as_true(t_barr *arr, size_t bit_index)
{
	size_t		word;
	uint16_t	bit;
	t_int_ws	mask;

	word = bit_index / WORD_SIZE;
	bit = bit_index & (WORD_SIZE - 1);
	mask = ((t_int_ws)1 << (WORD_SIZE - 1 - bit));
	arr->data[word] |= mask;
}

#endif
