/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:40:22 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:40:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "mode_libft.h"

static void	little_endian(char *bits, char *numptr, size_t typesize)
{
	size_t	pos;
	int		byte;
	int		bit;

	pos = 0;
	byte = typesize - 1;
	while (byte >= 0)
	{
		bit = 7;
		while (bit >= 0)
		{
			bits[pos++] = ((numptr[byte] >> bit) & 1) + '0';
			--bit;
		}
		bits[pos++] = ' ';
		--byte;
	}
	bits[pos - 1] = '\0';
}

static void	big_endian(char *bits, char *numptr, size_t typesize)
{
	size_t	pos;
	size_t	byte;
	int		bit;

	pos = 0;
	byte = 0;
	while (byte < typesize)
	{
		bit = 7;
		while (bit >= 0)
		{
			bits[pos++] = ((numptr[byte] >> bit) & 1) + '0';
			--bit;
		}
		bits[pos++] = ' ';
		++byte;
	}
	bits[pos - 1] = '\0';
}

#ifdef XMALLOC_MODE

char		*convert_num_to_bits_str(void *numptr, size_t typesize)
{
	char	*bits;

	bits = malloc(typesize * 8 + typesize);
	if (!bits)
		ft_error("can\'t allocate memory", "num_to_bits", 0);
	if (bytes_order() == FT_LITTLE_ENDIAN)
		little_endian(bits, numptr, typesize);
	else
		big_endian(bits, numptr, typesize);
	return (bits);
}

#else

char		*num_to_bits(void *numptr, size_t typesize)
{
	char	*bits;

	bits = malloc(typesize * 8 + typesize);
	if (!bits)
		return (NULL);
	if (bytes_order() == FT_LITTLE_ENDIAN)
		little_endian(bits, numptr, typesize);
	else
		big_endian(bits, numptr, typesize);
	return (bits);
}

#endif
