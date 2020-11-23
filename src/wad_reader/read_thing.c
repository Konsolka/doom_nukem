/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_thing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:52:44 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:42:43 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_prototypes.h"
#include "file.h"
#include "includes/libft.h"

static void	read_thing_data(const uint8_t *p_wad_data, int offset, t_thing *thing)
{
	thing->x_pos = bytes_to_short(p_wad_data, offset);
	thing->y_pos = bytes_to_short(p_wad_data, offset + 2);
	thing->angle = bytes_to_short(p_wad_data, offset + 4);
	thing->type = bytes_to_short(p_wad_data, offset + 6);
	thing->flag = bytes_to_short(p_wad_data, offset + 8);
}

bool	read_map_thing(t_file file, int index)
{
	int		i;
	int		i_thing_count;
	t_thing	thing;

	index += e_THINGS;
	if (ft_strcmp(file.dir[index].lump_name, "THINGS") != 0)
	{
		printf("Error in read_map_thing::ft_strcmp %s != THINGS", file.dir[index].lump_name);
		return (false);
	}
	i_thing_count = file.dir[index].lump_size / sizeof(t_thing);
	file.map.things = vec_create(i_thing_count, sizeof(t_thing));
	i = 0;
	while (i < i_thing_count)
	{
		read_thing_data(file.p_wad_data, file.dir[index].lump_offset + i * sizeof(t_thing), &thing);
		vec_pushback(&file.map.things, &thing);
		// printf("x_pos = %d   y_pos = %d   angle = %d   type = %d   flags = %d\n", file.map.things[i].x_pos, file.map.things[i].y_pos,
		// 			file.map.things[i].angle, file.map.things[i].type, file.map.things[i].flag);
		i++;
	}
	return (true);
}