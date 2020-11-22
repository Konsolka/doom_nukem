/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:02:30 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/22 17:56:45 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELDS_H
# define FIELDS_H

# include <stdint.h>

enum			e_mapLumpsIndex
{
    e_THINGS = 1,
    e_LINEDEFS,
    e_SIDEDDEFS,
    e_VERTEXES,
    e_SEAGS,
    e_SSECTORS,
    e_NODES,
    e_SECTORS,
    e_REJECT,
    e_BLOCKMAP,
    e_COUNT
};

typedef struct	s_vertex
{
	int16_t		xPos;
	int16_t		yPos;
}				t_vertex;

typedef struct	s_linedef
{
	uint16_t	startVertex;
	uint16_t	endVertex;
	uint16_t	flags;
	uint16_t	lineTypes;
	uint16_t	sectorTag;
	uint16_t	frontSidedef;
	uint16_t	backSidedef;
}				t_linedef;

typedef struct	s_map
{
	char		*name;
	t_vertex	*vertex;
	t_linedef	*linedef;
}				t_map;

#endif