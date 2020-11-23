/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:17:37 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 16:20:19 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEGS_H
# define SEGS_H

# include <stdint.h>

/*
** int16_t	Starting vertex number
** int16_t	Ending vertex number
** int16_t	Angle, full circle is -32768 to 32767.
** int16_t	Linedef number
** int16_t	Direction: 0 (same as linedef) or 1 (opposite of linedef)
** int16_t	Offset: distance along linedef to start of seg
*/
typedef struct	s_segs
{
	int16_t		start_vertex;
	int16_t		end_vertex;
	int16_t		angle;
	int16_t		linedef_num;
	int16_t		direct;
	int16_t		offset;
}				t_segs;
#endif