/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:46:38 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:38:10 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEDEF_H
# define LINEDEF_H

# include <stdint.h>

typedef struct	s_linedef
{
	uint16_t	start_vertex;
	uint16_t	end_vertex;
	uint16_t	flags;
	uint16_t	line_types;
	uint16_t	sector_tag;
	uint16_t	front_sidedef;
	uint16_t	back_sidedef;
}				t_linedef;

#endif
