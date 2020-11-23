/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_segs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:16:46 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 16:28:56 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "doom_prototypes.h"
#include "includes/libft.h"

static void	read_segs_data(const uint8_t *p_wad_data, int offset, t_segs *segs)
{
	segs->start_vertex = bytes_to_short(p_wad_data, offset);
	segs->end_vertex = bytes_to_short(p_wad_data, offset + 2);
	segs->angle = bytes_to_short(p_wad_data, offset + 4);
	segs->linedef_num = bytes_to_short(p_wad_data, offset + 6);
	segs->direct = bytes_to_short(p_wad_data, offset + 8);
	segs->offset = bytes_to_short(p_wad_data, offset + 10);
}

bool	read_map_segs(t_file file, int index)
{
	int		i;
	int		i_segs_count;
	t_segs	segs;

	index += e_SEGS;
	if (ft_strcmp(file.dir[index].lump_name, "SEGS") != 0)
	{
		printf("Error in read_map_segs::ft_strcmp %s != SEGS", file.dir[index].lump_name);
		return (false);
	}
	i_segs_count = file.dir[index].lump_size / sizeof(t_segs);
	file.map.segs = vec_create(i_segs_count, sizeof(t_segs));
	i = 0;
	while (i < i_segs_count)
	{
		read_segs_data(file.p_wad_data, file.dir[index].lump_offset + i * sizeof(t_segs), &segs);
		vec_pushback(&file.map.segs, &segs);
		// printf("sVertex = %d   eVertex = %d   angle = %d   linedef_num = %d   direction = %d   offset = %d\n",
		// 	file.map.segs[i].start_vertex,
		// 	file.map.segs[i].end_vertex,
		// 	file.map.segs[i].angle,
		// 	file.map.segs[i].linedef_num,
		// 	file.map.segs[i].direct,
		// 	file.map.segs[i].offset);
		i++;
	}
	return (true);
}