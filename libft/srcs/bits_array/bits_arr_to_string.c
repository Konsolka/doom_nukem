/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:44 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 18:19:50 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"
#include "mode_libft.h"

#ifdef XMALLOC_MODE

# ifdef SAFE_MODE

char			*barr_to_string(t_barr *arr)
{
	char		*bits;

	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_to_string", 0);
	bits = malloc(arr->size_in_int_ws * WORD_SIZE + 1);
	if (!bits)
		ft_error("can\'t allocate string", "barr_to_string", 0);
	convert_to_string(bits, arr->data, arr->size_in_int_ws);
	bits[arr->size_in_bits] = '\0';
	return (bits);
}

# else

char			*barr_to_string(t_barr *arr)
{
	char		*bits;

	bits = malloc(arr->size_in_int_ws * WORD_SIZE + 1);
	if (!bits)
		ft_error("can\'t allocate string", "barr_to_string", 0);
	convert_to_string(bits, arr->data, arr->size_in_int_ws);
	bits[arr->size_in_bits] = '\0';
	return (bits);
}

# endif

#else

# ifdef SAFE_MODE

char			*barr_to_string(t_barr *arr)
{
	char		*bits;

	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_to_string", 0);
	bits = malloc(arr->size_in_int_ws * WORD_SIZE + 1);
	if (!bits)
		return (NULL);
	convert_to_string(bits, arr->data, arr->size_in_int_ws);
	bits[arr->size_in_bits] = '\0';
	return (bits);
}

# else

char			*barr_to_string(t_barr *arr)
{
	char		*bits;

	bits = malloc(arr->size_in_int_ws * WORD_SIZE + 1);
	if (!bits)
		return (NULL);
	convert_to_string(bits, arr->data, arr->size_in_int_ws);
	bits[arr->size_in_bits] = '\0';
	return (bits);
}

# endif

#endif
