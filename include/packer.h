/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:03:56 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/29 21:46:29 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKER_H
# define PACKER_H

# include <stdint.h>

typedef struct s_readed_file
{
	uint8_t	*content;
	size_t	size;
}				t_readed_file;

typedef struct	s_pack_dir
{
	char			name[8];
	size_t			*offsets;
	t_readed_file	*files;
}				t_pack_dir;

typedef struct	s_pak_file
{
	t_header		header;
	t_pack_dir		dir[4];
}				t_pak_file;

#endif