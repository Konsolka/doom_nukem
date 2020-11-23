/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:20:22 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/23 16:45:28 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/libft.h"
#include "file.h"
#include "doom_prototypes.h"

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

void	read_header(const uint8_t *p_wad_data, int offset, t_header *header)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		header->wad_type[i] = p_wad_data[offset + i];
		i++;
	}
	header->wad_type[4] = '\0';
	header->dir_count = bytes_to_integer(p_wad_data, offset + 4);
	header->dir_offset = bytes_to_integer(p_wad_data, offset + 8);
	// printf("WAD Type = %s\nDir Offset = %d\nDir Count = %d\n", header->wad_type, header->dir_offset, header->dir_count);
}

void	read_dir_data(const uint8_t *p_wad_data, int offset, t_directory *dir)
{
	int		i;

	i = 0;
	dir->lump_offset = bytes_to_integer(p_wad_data, offset);
	dir->lump_size = bytes_to_integer(p_wad_data, offset + 4);
	while (i < 8)
	{
		dir->lump_name[i] = p_wad_data[offset + i + 8];
		i++;
	}
	dir->lump_name[8] = '\0';
	
}
void	wad_reader(t_file *file)
{
	t_directory dir;
	uint32_t	i;

	read_header(file->p_wad_data, 0, &file->header);
	i = 0;
	file->dir = vec_create(file->header.dir_count, sizeof(t_directory));
	while (i < file->header.dir_count)
	{
		read_dir_data(file->p_wad_data, file->header.dir_offset + 16 * i, &dir);
		vec_pushback(&file->dir, &dir);
		// printf("name = %s   offset = %d   size = %d\n", file->dir[i].lump_name, file->dir[i].lump_offset, file->dir[i].lump_size);
		i++;
	}
}

t_file	read_wad(const char *path)
{
	t_file	file;

	file.p_wad_data = wad_loader(path);
	wad_reader(&file);
	return (file);
}

void	load_map(const char *name, t_file file)
{
	int		index;

	if ((index = find_map_index(file, name)) < 0)
		ft_exit("Error in", "load_map::find_map_index", "", 1);
	// printf("Error in read_map_thing::find_map_index index = %d", index);
	printf("LOADING VERTEX\n");
	if (!read_map_vertex(file, index))
		ft_exit("Error: in", "read_map_vertex MAP:", name, 2);
	printf("LOADING LINEDEF\n");
	if (!read_map_linedef(file, index))
		ft_exit("Error: in", "read_map_linedef MAP:", name, 3);
	printf("LOADING THINGS\n");
	if (!read_map_thing(file, index))
		ft_exit("Error: in", "read_map_linedef MAP:", name, 4);
	printf("LOADING SIDEDEFS\n");
	if (!read_map_sidedef(file, index))
		ft_exit("Error: in", "read_map_sidedef MAP:", name, 5);
	printf("LOADING SEGS\n");
	if (!read_map_segs(file, index))
		ft_exit("Error: in", "read_map_segs Map:", name, 6);
	printf("LOADING SSECTORS\n");
	if (!read_map_ssectors(file, index))
		ft_exit("Error: in", " read_map_sectors MAP:", name, 7);
}

int		main(int ac, char **av)
{
	t_file	file;

	file = read_wad(av[1]);
	load_map("E1M1", file);
	free(file.p_wad_data);
	(void)ac;
	exit(0);
	return (0);	
}