/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 11:45:46 by user              #+#    #+#             */
/*   Updated: 2020/04/18 11:45:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static size_t	sizeof_num(int64_t num, unsigned base)
{
	size_t size;

	if (!num)
		return (1);
	if (base == 10 && num < 0)
		num = -num;
	size = 0;
	while (num)
	{
		++size;
		num /= base;
	}
	return (size);
}

char			*ft_itoa(int64_t num, char *str, unsigned radix)
{
	const char		*alphabet = "0123456789abcdef";
	const size_t	numsize = sizeof_num(num, radix);
	char			*iter;

	if (!str)
		str = malloc(numsize + (num < 0) + 1);
	iter = str + numsize + (num < 0);
	*iter-- = '\0';
	if (radix == 10 && num < 0)
	{
		*str = '-';
		num = -num;
	}
	if (!num)
		*iter = '0';
	while (num)
	{
		*iter-- = alphabet[num % radix];
		num /= radix;
	}
	return (str);
}
