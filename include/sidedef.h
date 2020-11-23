/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:12:36 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 13:45:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIDEDEF_H
# define SIDEDEF_H

#include <stdint.h>

typedef struct	s_sidedef
{
	int16_t		xOffset;
	int16_t		yOffset;
	int8_t		upTex[8];
	int8_t		downTex[8];
	int8_t		midTex[8];
	int16_t		sector;
}				t_sidedef;
#endif