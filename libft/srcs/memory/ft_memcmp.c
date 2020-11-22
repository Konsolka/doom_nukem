/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:04 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/10 13:49:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	register unsigned char *str1;
	register unsigned char *str2;

	str1 = (unsigned char*)memptr1;
	str2 = (unsigned char*)memptr2;
	while (num > 0)
	{
		if (*str1++ != *str2++)
			return (str1[-1] - str2[-1]);
		--num;
	}
	return (0);
}
