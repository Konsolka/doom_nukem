/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:58:33 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 13:34:30 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_UTILS_H
# define DOOM_UTILS_H
# include <stdint.h>

uint32_t	bytes_to_integer(const uint8_t *pWADData, int offset);
uint16_t	bytes_to_short(const uint8_t *pWADData, int offset);

#endif