/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:45:13 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/23 15:40:35 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdio.h>		//DELETE WHEN
# include <stdint.h>
# include "linedef.h"
# include "sidedef.h"
# include "thing.h"
# include "vertex.h"

enum			e_map_lumps_index
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

typedef struct	s_map
{
	char		*name;
	t_vertex	*vertex;
	t_linedef	*linedef;
	t_thing		*things;
	t_sidedef	*sidedef;
}				t_map;

typedef struct	s_header
{
	char		wad_type[5];
	uint32_t	dir_count;
	uint32_t	dir_offset;
}				t_header;

typedef struct	s_directory
{
	uint32_t	lump_offset;
	uint32_t	lump_size;
	char		lump_name[9];
}				t_directory;

typedef struct	s_file
{
	uint8_t		*p_wad_data;
	t_header	header;
	t_directory	*dir;
	t_map		map;
	
}				t_file;

#endif