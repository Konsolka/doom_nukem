/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:20:22 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/22 16:14:30 by konsolka         ###   ########.fr       */
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
	size_t	ret;
	
	data = NULL;
	wad_size = wad_len(path);
	data = (uint8_t *)malloc(sizeof(uint8_t) * (wad_size + 1));
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(1);
	ret = read(fd, data, wad_size);
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
	printf("%s=%d=%d", header->WADType, header->DirOffset, header->DirCount);
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
t_file	wad_reader(uint8_t *wad)
{
	t_file	file;
	uint32_t	i;

	read_header(wad, 0, &file.header);
	i = 0;
	while (i < file.header.DirCount)
	{
		read_dir_data(wad, file.header.DirOffset + 16 * i, &file.dir);
		printf("\n%s=%d=%d\n", file.dir.LumpName, file.dir.LumpOffset, file.dir.LumpSize);
		i++;
	}
	return (file);
}

void	read_wad(const char *path)
{
	uint8_t *wad;
	t_file	file;

	wad = wad_loader(path);
	file = wad_reader(wad);
	free(wad);
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

int		main(int ac, char **av)
{
	read_wad(av[1]);
	return (0);	
}