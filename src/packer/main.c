#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "doom_prototypes.h"
#include "file.h"
#include "includes/libft.h"
#include "packer.h"

t_header	create_header(size_t *size)
{
	t_header	header;

	header.dir_count = 0;
	header.dir_offset = sizeof(t_header);
	header.wad_type[0] = 'L';
	header.wad_type[1] = 'W';
	header.wad_type[2] = 'A';
	header.wad_type[3] = 'D';
	header.wad_type[4] = '\0';
	*size += sizeof(t_header);
	return (header);
}

size_t		size_file(const char *path)
{
	int		fd;
	size_t	ret;
	char	buf[100];
	size_t	size_of_file;
	uint8_t	*content;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("Error in opening file", "size_file", path, 2);
	while ((ret = read(fd, buf, 99)) > 0)
		size_of_file += ret;
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("Error in opening file", "size_file", path, 2);
	// content = malloc(sizeof(uint8_t) * size_of_file);
	content = NULL;
	if (read(fd, content, size_of_file) < 1)
		ft_exit("Error in reading file", "size_file:read", path, 3);
	free (content);
	close(fd);
	return (size_of_file);
}

int main(int ac, char **av)
{
	int fd;
	size_t	size;
	t_file	file;
	uint8_t	*line;

	// if (fd = open("pack.dat", O_WRONLY) == -1)
	// 	ft_exit("Error in opening file", " open ", "pack.dat", 1);
	line = NULL;
	size = 0;
	file.header = create_header(&size);
	size_file(av[1]);
	(void)ac;
	// close(fd);
	return (0);
}