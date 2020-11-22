/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:39:30 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:39:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_swap(void *restrict ptr1, void *restrict ptr2, size_t bytes)
{
	t_int_ws	buf;
	char		temp;

	while (bytes > WORD_SIZE_BYTES)
	{
		buf = *(t_int_ws*)ptr1;
		*(t_int_ws*)ptr1 = *(t_int_ws*)ptr2;
		*(t_int_ws*)ptr2 = buf;
		ptr1 += WORD_SIZE_BYTES;
		ptr2 += WORD_SIZE_BYTES;
		bytes -= WORD_SIZE_BYTES;
	}
	while (bytes)
	{
		temp = *(char*)ptr1;
		*(char*)ptr1 = *(char*)ptr2;
		*(char*)ptr2 = temp;
		++ptr1;
		++ptr2;
		--bytes;
	}
}
