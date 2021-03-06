/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:12:36 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:40:18 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIDEDEF_H
# define SIDEDEF_H

# include <stdint.h>

typedef struct	s_sidedef
{
	int16_t		x_offset;
	int16_t		yOffset;
	int8_t		up_tex[9];
	int8_t		low_tex[9];
	int8_t		mid_tex[9];
	int16_t		sector;
}				t_sidedef;


#endif