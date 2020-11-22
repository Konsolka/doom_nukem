/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:17:34 by dbendu            #+#    #+#             */
/*   Updated: 2020/02/10 13:52:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*src;
	char	*dst;
	size_t	i;

	i = -1;
	src = (char *)srcptr;
	dst = (char *)destptr;
	if (src < dst)
		while ((int)(--num) >= 0)
			*(dst + num) = *(src + num);
	else
		while (++i < num)
			*(dst + i) = *(src + i);
	return (destptr);
}
