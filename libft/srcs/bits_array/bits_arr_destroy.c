/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_arr_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:47 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 17:06:47 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bits_arr.h"
#include "private_bits_array.h"

#ifdef SAFE_MODE

void			barr_destroy(t_barr *arr)
{
	if (!arr)
		ft_error("invalid param \"arr\": NULL", "barr_destroy", 0);
	free(arr->data);
	free(arr);
}

#else

void			barr_destroy(t_barr *arr)
{
	free(arr->data);
	free(arr);
}

#endif
