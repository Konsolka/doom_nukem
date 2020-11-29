#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "doom_prototypes.h"
#include "file.h"
#include "includes/libft.h"
#include "packer.h"

t_header	create_header()
{
	t_header	header;

	header.dir_count = 0;
	header.dir_offset = sizeof(t_header);
	header.wad_type[0] = 'L';
	header.wad_type[1] = 'W';
	header.wad_type[2] = 'A';
	header.wad_type[3] = 'D';
	header.wad_type[4] = '\0';
	return (header);
}

void		read_file(const char *path, t_readed_file *f)
{
	int		fd;
	size_t	ret;
	char	buf[100];


	f->size = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("Error in opening file", "size_file", path, 2);
	while ((ret = read(fd, buf, 99)) > 0)
		f->size += ret;
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("Error in opening file", "size_file", path, 2);
	f->content = NULL;
	if ((f->content = malloc(sizeof(uint8_t) * f->size)) == NULL)
		ft_exit("Error in malloc for content", "read_file::malloc", "", 5);
	if (read(fd, f->content, f->size) < 1)
		ft_exit("Error in reading file", "size_file:read", path, 3);
	close(fd);
}

void	write_to_file(int fd, void *src, size_t size)
{
	uint8_t	*line;

	line = malloc(size);
	line = ft_memcpy(line, src, size);
	if (write(fd, line, size) < 0)
		ft_exit("Error in writing to file", "write_to_file::write", "", 4);
	free(line);
}

t_pack_dir	create_dirs(t_pack_dir *dirs)
{
	
}
int main(int ac, char **av)
{
	int fd;
	t_pak_file	file;
	t_readed_file	temp_file;

	if ((fd = open("pack.dat", O_WRONLY | O_CREAT)) == -1)
		ft_exit("Error in opening file", "open", "pack.dat", 1);
	chmod("pack.dat", S_IXUSR | S_IRUSR | S_IWUSR);
	file.header = create_header();
	create_dirs(file.dir);
	file.files = vec_create(1, sizeof(t_pak_file));
	read_file(av[1], &temp_file);
	(void)ac;
	write_to_file(fd, &file.header.wad_type, sizeof(file.header.wad_type));
	write_to_file(fd, &file.header.dir_count, sizeof(file.header.dir_count));
	write_to_file(fd, &file.header.dir_offset, sizeof(file.header.dir_offset));
	close(fd);
	return (0);
}