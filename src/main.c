/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:20:22 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/22 19:57:36 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/libft.h"
#include <stdio.h>
#include "file.h"
#include "fields.h"

size_t	wad_len(const char *path)
{
	size_t	wad_len;
	size_t	ret;
	int		fd;
	char	buf[128];

	wad_len = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(1);
	while ((ret = read(fd, buf, 127)) > 0)
		wad_len += ret;
	close(fd);
	return (wad_len);
}

uint8_t	*wad_loader(const char *path)
{
	uint8_t	*data;
	size_t	wad_size;
	int		fd;
	
	data = NULL;
	wad_size = wad_len(path);
	data = (uint8_t *)malloc(sizeof(uint8_t) * (wad_size + 1));
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(1);
	read(fd, data, wad_size);
	close(fd);
	return (data);
}

uint32_t	bytes_to_integer(const uint8_t *pWADData, int offset)
{
	return ((pWADData[offset + 3] << 24) | (pWADData[offset + 2] << 16) | (pWADData[offset + 1] << 8) | pWADData[offset]);
}

uint16_t	bytes_to_short(const uint8_t *pWADData, int offset)
{
	return ((pWADData[offset + 1] << 8) | pWADData[offset]);
}
void	read_header(const uint8_t *pWADData, int offset, t_header *header)
{
	header->WADType[0] = pWADData[offset];
	header->WADType[1] = pWADData[offset + 1];
	header->WADType[2] = pWADData[offset + 2];
	header->WADType[3] = pWADData[offset + 3];
	header->WADType[4] = '\0';

	header->DirCount = bytes_to_integer(pWADData, offset + 4);
	header->DirOffset = bytes_to_integer(pWADData, offset + 8);
	printf("WAD Type = %s\nDir Offset = %d\nDir Count = %d\n", header->WADType, header->DirOffset, header->DirCount);
}

void	read_dir_data(const uint8_t *pWADData, int offset, t_directory *dir)
{
	int		i;

	i = 0;
	dir->LumpOffset = bytes_to_integer(pWADData, offset);
	dir->LumpSize = bytes_to_integer(pWADData, offset + 4);
	while (i < 8)
	{
		dir->LumpName[i] = pWADData[offset + i + 8];
		i++;
	}
	dir->LumpName[8] = '\0';
	
}
void	wad_reader(t_file *file)
{
	t_directory dir;
	uint32_t	i;

	read_header(file->pWADData, 0, &file->header);
	i = 0;
	file->dir = vec_create(file->header.DirCount, sizeof(t_directory));
	while (i < file->header.DirCount)
	{
		read_dir_data(file->pWADData, file->header.DirOffset + 16 * i, &dir);
		vec_pushback(&file->dir, &dir);
		printf("name = %s   offset = %d   size = %d\n", file->dir[i].LumpName, file->dir[i].LumpOffset, file->dir[i].LumpSize);
		i++;
	}
}


void	read_vertex_data(const uint8_t *pWADData, int offset, t_vertex *vertex)
{
	vertex->xPos = bytes_to_short(pWADData, offset);
	vertex->yPos = bytes_to_short(pWADData, offset + 2);
}

void	read_linedef_data(const uint8_t *pWADData, int offset, t_linedef *linedef)
{
	linedef->startVertex = bytes_to_short(pWADData, offset);
	linedef->endVertex = bytes_to_short(pWADData, offset + 2);
	linedef->flags = bytes_to_short(pWADData, offset + 4);
	linedef->lineTypes = bytes_to_short(pWADData, offset + 6);
	linedef->sectorTag = bytes_to_short(pWADData, offset + 8);
	linedef->frontSidedef = bytes_to_short(pWADData, offset + 10);
	linedef->backSidedef = bytes_to_short(pWADData, offset + 12);
}

t_file	read_wad(const char *path)
{
	t_file	file;

	file.pWADData = wad_loader(path);
	wad_reader(&file);
	return (file);
}

#include <stdbool.h>

int		find_map_index(t_file file, const char *name)
{
	int i;

	i = 0;
	while (i < vec_size(&file.dir))
	{
		if (ft_strcmp(file.dir[i].LumpName, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

bool	read_map_vertex(t_file file, const char *name)
{
	t_vertex vertex;
	int index;
	int	i;

	if ((index = find_map_index(file, name)) < 0)
	{
		printf("Error in find_map_index index = %d\n", index);
		return (false);								// WRITE ERROR
	}
	index += e_VERTEXES;
	if (ft_strcmp(file.dir[index].LumpName, "VERTEXES") != 0)
	{
		printf("Error in ft_strcmp\n");
		return (false);								// WRITE ERROR
	}
	int iVertexCount = file.dir[index].LumpSize / sizeof(t_vertex);
	i = 0;
	file.map.vertex = (t_vertex *)vec_create(iVertexCount, sizeof(t_vertex));
	while (i < iVertexCount)
	{
		read_vertex_data(file.pWADData, file.dir[index].LumpOffset + i * sizeof(t_vertex), &vertex);
		vec_pushback(&file.map.vertex, &vertex);
		printf("xPos = %d   yPos = %d\n", file.map.vertex[i].xPos, file.map.vertex[i].yPos);
		i++;
	}
	return (true);
}

bool	read_map_linedef(t_file file, const char *name)
{
	int index;
	int	i;
	int iLinedefCount;
	t_linedef	linedef;

	if ((index = find_map_index(file, name)) < 0)
	{
		printf("Error in read_map_linedef::find_map_index index = %d\n", index); // WRITE ERROR
		return (false);
	}
	index += e_LINEDEFS;
	if (ft_strcmp(file.dir[index].LumpName, "LINEDEFS") != 0)
	{
		printf("Error in read_map_linedef::ft_strcmp\n%s != LINEDEFS\n", file.dir[index].LumpName);
		return (false);								// WRITE ERROR
	}
	iLinedefCount = file.dir[index].LumpSize / sizeof(t_linedef);
	file.map.linedef = vec_create(iLinedefCount, sizeof(t_linedef));
	i = 0;
	while (i < iLinedefCount)
	{
		read_linedef_data(file.pWADData, file.dir[index].LumpOffset + i * sizeof(t_linedef), &linedef);
		vec_pushback(&file.map.linedef, &linedef);
		printf("start = %d  end = %d  flags = %d  Type = %d  Tag = %d  frontSd = %d  backSd = %d\n",
											file.map.linedef[i].startVertex,
											file.map.linedef[i].endVertex,
											file.map.linedef[i].flags,
											file.map.linedef[i].lineTypes,
											file.map.linedef[i].sectorTag,
											file.map.linedef[i].frontSidedef,
											file.map.linedef[i].backSidedef);
		i++;
	}
	return (true);
}

void	load_map(const char *name, t_file file)
{
	printf("===========================LOADING VERTEX==========================\n");
	if (!read_map_vertex(file, name))
	{
		printf("Error: Failed to load map vertex data MAP:%s\n", name);
		exit(1);
	}
	printf("===========================LOADING LINEDEF==========================\n");
	if (!read_map_linedef(file, name))
	{
		printf("Error: Failed to load map linedef data MAP:%s\n", name);
		exit(2);
	}
}

int		main(int ac, char **av)
{
	t_file	file;

	file = read_wad(av[1]);
	load_map("E1M1", file);
	free(file.pWADData);
	(void)ac;
	return (0);	
}