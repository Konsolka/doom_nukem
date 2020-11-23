/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:58:09 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:41:07 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "doom_prototypes.h"
#include "includes/libft.h"

uint32_t	bytes_to_integer(const uint8_t *p_wad_data, int offset)
{
	return ((p_wad_data[offset + 3] << 24) | (p_wad_data[offset + 2] << 16) | (p_wad_data[offset + 1] << 8) | p_wad_data[offset]);
}

uint16_t	bytes_to_short(const uint8_t *p_wad_data, int offset)
{
	return ((p_wad_data[offset + 1] << 8) | p_wad_data[offset]);
}

int		find_map_index(t_file file, const char *name)
{
	int i;

	i = 0;
	while (i < vec_size(&file.dir))
	{
		if (ft_strcmp(file.dir[i].lump_name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_exit(const char *msg, const char *func_name, const char *add_msg,
										int exit_code)
{
	write(2, msg, ft_strlen(msg));
	write(2, " ", 1);
	write(2, func_name, ft_strlen(func_name));
	write(2, " ", 1);
	write(2, add_msg, ft_strlen(add_msg));
	write(2, "\n", 1);
	exit(exit_code);
}