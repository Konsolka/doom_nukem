/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:08:03 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 16:44:17 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_PROTOTYPES_H
# define DOOM_PROTOTYPES_H

# include <stdbool.h>
# include "file.h"

/*
** reading data from wad file
*/
bool		read_map_linedef(t_file file, int index);
bool		read_map_vertex(t_file file, int index);
bool		read_map_sidedef(t_file file, int index);
bool		read_map_thing(t_file file, int index);
bool		read_map_segs(t_file file, int index);
bool		read_map_ssectors(t_file file, int index);


/*
** ===========================UTILS===========================
*/

uint32_t	bytes_to_integer(const uint8_t *p_wad_data, int offset);
uint16_t	bytes_to_short(const uint8_t *p_wad_data, int offset);
int			find_map_index(t_file file, const char *name);

/*
** msg - message for output
** func_name - name of function
** add_msg - additional message
** exit_code - exit code
*/
void		ft_exit(const char *msg, const char *func_name, const char *add_msg,
										int exit_code);
#endif
