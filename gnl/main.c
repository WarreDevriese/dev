#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free (str);
	}
	close(fd);
	return (0);
}
