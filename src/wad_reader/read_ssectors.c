/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sssectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:29:56 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 16:42:24 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "doom_prototypes.h"
#include "includes/libft.h"

static void	read_ssectors_data(const uint8_t *p_wad_data, int offset, t_ssectors *ssectors)
{
	ssectors->seg_count = bytes_to_short(p_wad_data, offset);
	ssectors->first_seg_num = bytes_to_short(p_wad_data, offset + 2);
}

bool	read_map_ssectors(t_file file, int index)
{
	int		i;
	int		i_ssectors_count;
	t_ssectors	ssectors;

	index += e_SSECTORS;
	if (ft_strcmp(file.dir[index].lump_name, "SSECTORS") != 0)
	{
		printf("Error in read_map_ssectors::ft_strcmp %s != Sssectors", file.dir[index].lump_name);
		return (false);
	}
	i_ssectors_count = file.dir[index].lump_size / sizeof(t_ssectors);
	file.map.ssectors = vec_create(i_ssectors_count, sizeof(t_ssectors));
	i = 0;
	while (i < i_ssectors_count)
	{
		read_ssectors_data(file.p_wad_data, file.dir[index].lump_offset + i * sizeof(t_ssectors), &ssectors);
		vec_pushback(&file.map.ssectors, &ssectors);
		// printf("seg_count = %d   first_seg_num = %d\n",
		// 			file.map.ssectors[i].seg_count,
		// 			file.map.ssectors[i].first_seg_num);
		i++;
	}
	return (true);
}
