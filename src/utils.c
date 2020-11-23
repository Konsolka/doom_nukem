/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:58:09 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 12:58:21 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	bytes_to_integer(const uint8_t *pWADData, int offset)
{
	return ((pWADData[offset + 3] << 24) | (pWADData[offset + 2] << 16) | (pWADData[offset + 1] << 8) | pWADData[offset]);
}

uint16_t	bytes_to_short(const uint8_t *pWADData, int offset)
{
	return ((pWADData[offset + 1] << 8) | pWADData[offset]);
}