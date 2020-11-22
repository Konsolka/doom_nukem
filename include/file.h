/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:45:13 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/22 18:00:53 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <stdint.h>
# include "fields.h"

typedef struct	s_header
{
	char WADType[5];
	uint32_t	DirCount;
	uint32_t	DirOffset;
}				t_header;

typedef struct	s_directory
{
	uint32_t	LumpOffset;
	uint32_t	LumpSize;
	char		LumpName[9];
}				t_directory;

typedef struct	s_file
{
	uint8_t		*pWADData;
	t_header	header;
	t_directory	*dir;
	t_map		map;
	
}				t_file;
#endif