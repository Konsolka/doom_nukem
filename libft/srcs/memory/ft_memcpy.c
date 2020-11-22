/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:15 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/03 12:37:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_memory.h"

/*
** num always multiple of __WORDSIZE
*/

static void		fast_memcpy(void *restrict dstptr,
							const void *restrict srcptr,
							size_t num)
{
	register t_int_ws	*dst;
	register t_int_ws	*src;

	num /= WORD_SIZE_BYTES;
	dst = (t_int_ws*)dstptr;
	src = (t_int_ws*)srcptr;
	while (num > 1)
	{
		*dst = *src;
		dst[1] = src[1];
		dst += 2;
		src += 2;
		num -= 2;
	}
	if (num)
		*dst = *src;
}

void			*ft_memcpy(void *restrict dstptr,
							const void *restrict srcptr,
							size_t bytes)
{
	void		*dst;

	dst = dstptr;
	if (bytes > 64)
	{
		fast_memcpy(dstptr, srcptr, bytes & ~(WORD_SIZE_BYTES - 1));
		dstptr += bytes & ~(WORD_SIZE_BYTES - 1);
		srcptr += bytes & ~(WORD_SIZE_BYTES - 1);
		bytes &= (WORD_SIZE_BYTES - 1);
	}
	while (bytes > 1)
	{
		*(char*)dstptr++ = *(char*)srcptr++;
		*(char*)dstptr++ = *(char*)srcptr++;
		bytes -= 2;
	}
	if (bytes)
		*(char*)dstptr = *(char*)srcptr;
	return (dst);
}
