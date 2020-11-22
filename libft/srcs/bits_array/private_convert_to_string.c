/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_convert_to_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:18:41 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 18:23:07 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bits_array.h"

static void		little_endian(char *str, char *numptr)
{
	int			byte;
	int			bit;

	byte = WORD_SIZE_BYTES - 1;
	while (byte >= 0)
	{
		bit = 7;
		while (bit >= 0)
		{
			*str = ((numptr[byte] >> bit) & 1) + '0';
			++str;
			--bit;
		}
		--byte;
	}
}

static void		big_endian(char *str, char *numptr)
{
	int			byte;
	int			bit;

	byte = 0;
	while (byte < 8)
	{
		bit = 7;
		while (bit >= 0)
		{
			*str = ((numptr[byte] >> bit) & 1) + '0';
			++str;
			--bit;
		}
		++byte;
	}
}

void			convert_to_string(char *str, t_int_ws *data, size_t datalen)
{
	size_t		cur_num;

	cur_num = 0;
	if (bytes_order() == FT_LITTLE_ENDIAN)
	{
		while (cur_num < datalen)
		{
			little_endian(str, (char*)(data + cur_num));
			str += WORD_SIZE;
			++cur_num;
		}
	}
	else
	{
		while (cur_num < datalen)
		{
			big_endian(str, (char*)(data + cur_num));
			str += WORD_SIZE;
			++cur_num;
		}
	}
}
