/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sidedef.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:55:06 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:42:38 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_prototypes.h"
#include "file.h"
#include "includes/libft.h"

static void	read_sidedef_data(const uint8_t *p_wad_data, int offset, t_sidedef *sidedef)
{
	int		i;
	sidedef->x_offset = bytes_to_short(p_wad_data, offset);
	sidedef->yOffset = bytes_to_short(p_wad_data, offset + 2);
	i = 0;
	while (i < 8)
	{
		sidedef->up_tex[i] = p_wad_data[offset + 4 + i];
		i++;
	}
	sidedef->up_tex[i] = '\0';
	i = 0;
	while (i < 8)
	{
		sidedef->low_tex[i] = p_wad_data[offset + 12 + i];
		i++;
	}
	sidedef->low_tex[i] = '\0';
	i = 0;
	while (i < 8)
	{
		sidedef->mid_tex[i] = p_wad_data[offset + 20 + i];
		i++;
	}
	sidedef->mid_tex[i] = '\0';
	sidedef->sector = bytes_to_short(p_wad_data, offset + 28);
}

bool	read_map_sidedef(t_file file, int index)
{
	int	i;
	int i_sidedef_count;
	size_t		size;
	t_sidedef	sidedef;

	index += e_SIDEDDEFS;
	if (ft_strcmp(file.dir[index].lump_name, "SIDEDEFS") != 0)
	{
		printf("Error in read_map_linedef::ft_strcmp\n%s != LINEDEFS\n", file.dir[index].lump_name);
		return (false);								// WRITE ERROR
	}
	size = sizeof(t_sidedef) - 4;
	i_sidedef_count = file.dir[index].lump_size / size;
	file.map.sidedef = vec_create(i_sidedef_count, sizeof(t_sidedef));
	i = 0;
	while (i < i_sidedef_count)
	{
		read_sidedef_data(file.p_wad_data, file.dir[index].lump_offset + i * size, &sidedef);
		vec_pushback(&file.map.sidedef, &sidedef);
		// printf("i = %d   x_offset = %d  yOffset = %d  up_tex = %s  lowTex = %s  mid_tex = %s  sector = %d\n",
		// 									i,
		// 									file.map.sidedef[i].x_offset,
		// 									file.map.sidedef[i].yOffset,
		// 									file.map.sidedef[i].up_tex,
		// 									file.map.sidedef[i].low_tex,
		// 									file.map.sidedef[i].mid_tex,
		// 									file.map.sidedef[i].sector);
		i++;
	}
	return (true);
}
