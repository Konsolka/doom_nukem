/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:43 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/03 12:36:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

static void		fast_memset(void *restrict dstptr, char c, size_t bytes)
{
	register t_int_ws	*dst;
	t_int_ws			buf;
	int					iter;

	buf = 0;
	iter = -1;
	while (++iter < WORD_SIZE_BYTES)
		buf += c << ((WORD_SIZE_BYTES - 1 - iter) * 8);
	bytes /= WORD_SIZE_BYTES;
	dst = (t_int_ws*)dstptr;
	while (bytes > 1)
	{
		*dst = buf;
		dst[1] = buf;
		dst += 2;
		bytes -= 2;
	}
	if (bytes)
		*dst = buf;
}

void			*ft_memset(void *restrict dest, int c, size_t bytes)
{
	void		*dst;

	dst = dest;
	if (bytes > 128)
	{
		fast_memset(dest, c, bytes & ~(WORD_SIZE_BYTES - 1));
		dest += bytes & ~(WORD_SIZE_BYTES - 1);
		bytes &= (WORD_SIZE_BYTES - 1);
	}
	while (bytes > 1)
	{
		*(char*)dest++ = c;
		*(char*)dest++ = c;
		bytes -= 2;
	}
	if (bytes)
		*(char*)dest = c;
	return (dst);
}
