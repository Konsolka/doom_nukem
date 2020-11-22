/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:16:56 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/03 12:34:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	register unsigned char	*str;
	unsigned char			val_;

	str = (unsigned char*)memptr;
	val_ = (unsigned char)val;
	while (num)
	{
		if (*str == (unsigned char)val_)
			return (str);
		++str;
		--num;
	}
	return (NULL);
}
