/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_linedef.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:44:42 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:42:32 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "doom_prototypes.h"
#include "includes/libft.h"

static void	read_linedef_data(const uint8_t *p_wad_data, int offset, t_linedef *linedef)
{
	linedef->start_vertex = bytes_to_short(p_wad_data, offset);
	linedef->end_vertex = bytes_to_short(p_wad_data, offset + 2);
	linedef->flags = bytes_to_short(p_wad_data, offset + 4);
	linedef->line_types = bytes_to_short(p_wad_data, offset + 6);
	linedef->sector_tag = bytes_to_short(p_wad_data, offset + 8);
	linedef->front_sidedef = bytes_to_short(p_wad_data, offset + 10);
	linedef->back_sidedef = bytes_to_short(p_wad_data, offset + 12);
}

bool	read_map_linedef(t_file file, int index)
{
	int	i;
	int i_linedef_count;
	t_linedef	linedef;

	index += e_LINEDEFS;
	if (ft_strcmp(file.dir[index].lump_name, "LINEDEFS") != 0)
	{
		printf("Error in read_map_linedef::ft_strcmp\n%s != LINEDEFS\n", file.dir[index].lump_name);
		return (false);								// WRITE ERROR
	}
	i_linedef_count = file.dir[index].lump_size / sizeof(t_linedef);
	file.map.linedef = vec_create(i_linedef_count, sizeof(t_linedef));
	i = 0;
	while (i < i_linedef_count)
	{
		read_linedef_data(file.p_wad_data, file.dir[index].lump_offset + i * sizeof(t_linedef), &linedef);
		vec_pushback(&file.map.linedef, &linedef);
		// printf("i = %d   start = %d  end = %d  flags = %d  Type = %d  Tag = %d  frontSd = %d  backSd = %d\n",
		// 									i,
		// 									file.map.linedef[i].start_vertex,
		// 									file.map.linedef[i].end_vertex,
		// 									file.map.linedef[i].flags,
		// 									file.map.linedef[i].line_types,
		// 									file.map.linedef[i].sector_tag,
		// 									file.map.linedef[i].front_sidedef,
		// 									file.map.linedef[i].back_sidedef);
		i++;
	}
	return (true);
}
