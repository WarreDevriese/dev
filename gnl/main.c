#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int fd = open(argv[1], O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free (str);
	}
	close(fd);
	return (0);
}
