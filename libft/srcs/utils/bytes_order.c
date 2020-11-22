/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:40:13 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:40:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int		bytes_order(void)
{
	uint16_t		n;
	unsigned char	c;

	n = 1;
	c = *(unsigned char*)&n;
	if (c)
		return (FT_LITTLE_ENDIAN);
	else
		return (FT_BIG_ENDIAN);
}
