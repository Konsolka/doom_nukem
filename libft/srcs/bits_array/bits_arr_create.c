/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:49 by dbendu            #+#    #+#             */
/*   Updated: 2020/11/04 15:16:49 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"

#ifdef XMALLOC_MODE

# ifdef SAFE_MODE

t_barr			*barr_create(size_t bits)
{
	t_barr		*barr;

	if (!bits)
		ft_error("invalid param: \"bits\" can not be 0", "barr_create", 0);
	barr = malloc(sizeof(t_barr));
	if (!barr)
		ft_error("can\'t allocate bytes array", "barr_create", 0);
	barr->size_in_bits = bits;
	barr->size_in_int_ws = bits / WORD_SIZE + ((bits & (WORD_SIZE - 1)) != 0);
	barr->data = malloc(barr->size_in_int_ws * sizeof(t_int_ws));
	if (!barr->data)
		ft_error("can\'t allocate data in bytes array", "barr_create", 0);
	ft_memset(barr->data, 0, barr->size_in_int_ws * sizeof(t_int_ws));
	return (barr);
}

# else

t_barr			*barr_create(size_t bits)
{
	t_barr		*barr;

	barr = malloc(sizeof(t_barr));
	if (!barr)
		ft_error("can\'t allocate bytes array", "barr_create", 0);
	barr->size_in_bits = bits;
	barr->size_in_int_ws = bits / WORD_SIZE + ((bits & (WORD_SIZE - 1)) != 0);
	barr->data = malloc(barr->size_in_int_ws * sizeof(t_int_ws));
	if (!barr->data)
		ft_error("can\'t allocate data in bytes array", "barr_create", 0);
	ft_memset(barr->data, 0, barr->size_in_int_ws * sizeof(t_int_ws));
	return (barr);
}

# endif

#else

# ifdef SAFE_MODE

t_barr			*barr_create(size_t bits)
{
	t_barr		*barr;

	if (!bits)
		ft_error("invalid param: \"bits\" can not be 0", "barr_create", 0);
	barr = malloc(sizeof(t_barr));
	if (!barr)
		return (NULL);
	barr->size_in_bits = bits;
	barr->size_in_int_ws = bits / WORD_SIZE + ((bits & (WORD_SIZE - 1)) != 0);
	barr->data = malloc(barr->size_in_int_ws * sizeof(t_int_ws));
	if (!barr->data)
	{
		free(barr);
		return (NULL);
	}
	ft_memset(barr->data, 0, barr->size_in_int_ws * sizeof(t_int_ws));
	return (barr);
}

# else

t_barr			*barr_create(size_t bits)
{
	t_barr		*barr;

	barr = malloc(sizeof(t_barr));
	if (!barr)
		return (NULL);
	barr->size_in_bits = bits;
	barr->size_in_int_ws = bits / WORD_SIZE + ((bits & (WORD_SIZE - 1)) != 0);
	barr->data = malloc(barr->size_in_int_ws * sizeof(t_int_ws));
	if (!barr->data)
	{
		free(barr);
		return (NULL);
	}
	ft_memset(barr->data, 0, barr->size_in_int_ws * sizeof(t_int_ws));
	return (barr);
}

# endif

#endif
