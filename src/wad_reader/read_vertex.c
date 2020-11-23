/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:48:35 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:42:48 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_prototypes.h"
#include "file.h"
#include "includes/libft.h"

static void	read_vertex_data(const uint8_t *p_wad_data, int offset, t_vertex *vertex)
{
	vertex->x_pos = bytes_to_short(p_wad_data, offset);
	vertex->y_pos = bytes_to_short(p_wad_data, offset + 2);
}

bool	read_map_vertex(t_file file, int index)
{
	t_vertex vertex;
	int	i;

	index += e_VERTEXES;
	if (ft_strcmp(file.dir[index].lump_name, "VERTEXES") != 0)
	{
		printf("Error in ft_strcmp\n");
		return (false);								// WRITE ERROR
	}
	int i_vertex_count = file.dir[index].lump_size / sizeof(t_vertex);
	i = 0;
	file.map.vertex = (t_vertex *)vec_create(i_vertex_count, sizeof(t_vertex));
	while (i < i_vertex_count)
	{
		read_vertex_data(file.p_wad_data, file.dir[index].lump_offset + i * sizeof(t_vertex), &vertex);
		vec_pushback(&file.map.vertex, &vertex);
		// printf("i = %d   x_pos = %d   y_pos = %d\n", i, file.map.vertex[i].x_pos, file.map.vertex[i].y_pos);
		i++;
	}
	return (true);
}
